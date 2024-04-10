namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;

        //for (k in 0 .. size - 1) {
        for (k in size - 1 .. -1 .. 0) {
            using (qs = Qubit[N]) {
                // Prepare k-th basis vector
                let binary = IntAsBoolArray(k, N);

                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);

                // Apply the operation
                unitary(qs);

                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");

                // ResetAll may leave global phase behind. Uncomment this to
                // avoid that.
                ResetAll(qs);
                //Adjoint unitary(qs);
                //ApplyPauliFromBitString(PauliX, true, binary, qs);
            }
        }
    }

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

    operation Solve (qs : Qubit[]) : Unit is Adj {
        let n = Length(qs);
        Controlled H(qs[1...], qs[0]);
        for (i in (2^n)-3..-1..0) {
            Swap(qs, i+0, 2^n-2);
            Swap(qs, i+1, 2^n-1);
            Controlled H(qs[1...], qs[0]);
            Swap(qs, i+0, 2^n-2);
            Swap(qs, i+1, 2^n-1);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        DumpUnitaryToFiles(4, Solve);
//    }
}