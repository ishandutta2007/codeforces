namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function FirstOne(n: Int, a : Int) : Int {
        mutable r = -1;
        for (i in 0..n-1) {
            if ((a >>> i) % 2 == 1 and r == -1) {
                set r = i;
            }
        }
        return r;
    }

    operation SwapImpl(qs : Qubit[], a : Int, b : Int, i0 : Int) : Unit is Adj {
        for (i in 0..Length(qs)-1) {
            let same = ((a^^^b)>>>i)%2==0;
            if (same and (a>>>i)%2==0) {
                X(qs[i]);
            }
            if (i>i0 and not same and (a>>>i)%2==(a>>>i0)%2) {
                X(qs[i]);
            }
            if (i>i0 and not same) {
                CNOT(qs[i0], qs[i]);
            }
        }
    }

    operation Swap(qs : Qubit[], a : Int, b : Int) : Unit is Adj {
        let i0 = FirstOne(Length(qs), a ^^^ b);
        SwapImpl(qs, a, b, i0);
        Controlled X(qs[...i0-1] + qs[i0+1...], qs[i0]);
        Adjoint SwapImpl(qs, a, b, i0);
    }

    function Log2Ceil(a : Int) : Int {
        for (i in 0..100) {
            if (2^i >= a) {
                return i;
            }
        }
        return -1;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let n = Log2Ceil(Length(qs));
        for (i in 0..n-1) {
            H(qs[i]);
        }
        for (i in Length(qs)-1..-1..0) {
            Swap(qs, i, 2^i);
        }
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    using (qs = Qubit[1]) {
    //        Solve(qs);
    //        DumpRegister((), qs);
    //        ResetAll(qs);
    //    }
    //}
}