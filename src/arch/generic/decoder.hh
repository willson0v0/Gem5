/*
 * Copyright 2020 Google, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ARCH_GENERIC_DECODER_HH__
#define __ARCH_GENERIC_DECODER_HH__

#include "base/bitfield.hh"
#include "base/intmath.hh"
#include "base/types.hh"
#include "cpu/static_inst_fwd.hh"

namespace gem5
{

class InstDecoder
{
  protected:
    void *_moreBytesPtr;
    size_t _moreBytesSize;
    Addr _pcMask;

  public:
    template <typename MoreBytesType>
    InstDecoder(MoreBytesType *mb_buf) :
        _moreBytesPtr(mb_buf), _moreBytesSize(sizeof(MoreBytesType)),
        _pcMask(~mask(floorLog2(_moreBytesSize)))
    {}

    virtual StaticInstPtr fetchRomMicroop(
            MicroPC micropc, StaticInstPtr curMacroop);

    void *moreBytesPtr() const { return _moreBytesPtr; }
    size_t moreBytesSize() const { return _moreBytesSize; }
    Addr pcMask() const { return _pcMask; }
};

} // namespace gem5

#endif // __ARCH_DECODER_GENERIC_HH__
