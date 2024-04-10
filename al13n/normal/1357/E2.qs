namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function ToInt(r : Result) : Int {
        if (r == One) {
            return 1;
        } else {
            return 0;
        }
    }
    function BoolToInt(r : Bool) : Int {
        if (r) {
            return 1;
        } else {
            return 0;
        }
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit is Adj)) : Unit {
        let size = 1 <<< N;

        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {
                // Prepare k-th basis vector
                let binary = IntAsBoolArray(k, N);

                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);

                // Apply the operation
                unitary(qs);

                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");

                //ResetAll(qs);
                Adjoint unitary(qs);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
            }
        }
    }


    operation Solve (p : Int, qs : LittleEndian) : Unit is Adj+Ctl {
        using ((a, b) = (Qubit(), Qubit())) {
            let pd = IntAsDouble(p);
            within {
                H(b);
                Controlled ApplyQuantumFourierTransform([b], qs);
                Controlled ApplyQuantumFourierTransform([b], qs);
                H(b);
                H(a);
                Controlled ApplyQuantumFourierTransform([a], qs);
                Controlled R1([b], (-PI()*.5, a));
                H(a);
            } apply {
              R1(PI()*.5/pd, b);
              R1(PI()   /pd, a);
            }
        }
    }

    operation doit2 (qs : Qubit[]) : Unit is Adj {
        Solve(2, LittleEndian(qs));
        Solve(2, LittleEndian(qs));
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    DumpUnitaryToFiles(3, doit2);
    //    //using (qs = Qubit[3]) {
    //    //    Ry(.123, qs[0]);
    //    //    Rz(.234, qs[0]);
    //    //    Ry(.111, qs[1]);
    //    //    Rz(.241, qs[1]);
    //    //    Ry(.564, qs[2]);
    //    //    Rz(.928, qs[2]);
    //    //    CNOT(qs[0], qs[1]);
    //    //    CCNOT(qs[1], qs[2], qs[0]);
    //    //    Solve(2, LittleEndian(qs));
    //    //    ResetAll(qs);
    //    //}
    //}
}