namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Unit {
        for (i in Length(qs)-2..-1..0) {
            CNOT(qs[Length(qs)-1], qs[i]);
        }
        for (i in Length(qs)-2..-1..0) {
            Controlled X(qs[0..i-1], qs[i]);
            X(qs[i]);
        }
        for (i in Length(qs)-2..-1..0) {
            CNOT(qs[Length(qs)-1], qs[i]);
        }
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
        H(qs[0]);
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
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
//        DumpUnitaryToFiles(4, Solve);
//    }
}