namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Flip(qs : Qubit[]) : Unit is Ctl {
        for (q in qs) {
            X(q);
        }
    }

    operation Inc(qs : Qubit[]) : Unit is Ctl {
        for (i in Length(qs)-1..-1..0) {
            Controlled X(qs[0..i-1], qs[i]);
        }
    }

    operation Dec(qs : Qubit[]) : Unit is Ctl {
        Flip(qs);
        Inc(qs);
        Flip(qs);
    }

    operation Solve (qs : Qubit[]) : Unit {
        Inc(qs);
        Inc(qs);
        Controlled Inc([qs[2]], qs[0..1]);
        Controlled Inc([qs[2]], qs[0..1]);
        Controlled Inc([qs[2]], qs[0..1]);
        Controlled H([qs[2]], qs[0]);
        Flip(qs);
        Controlled H([qs[2]], qs[0]);
        Controlled H([qs[2]], qs[1]);
        Inc(qs);
        Inc(qs);
        Flip(qs);
    }

//    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
//        let size = 1 <<< N;
//
//        using (qs = Qubit[N]) {
//            for (k in 0 .. size - 1) {
//                // Prepare k-th basis vector
//                let binary = IntAsBoolArray(k, N);
//
//                //Message($"{k}/{N} = {binary}");
//                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
//                ApplyPauliFromBitString(PauliX, true, binary, qs);
//
//                // Apply the operation
//                unitary(qs);
//
//                // Dump the contents of the k-th column
//                DumpMachine($"DU_{N}_{k}.txt");
//
//                ResetAll(qs);
//            }
//        }
//    }
//
//    @EntryPoint()
//    operation test() : Unit {
//        DumpUnitaryToFiles(3, Solve);
//    }
}