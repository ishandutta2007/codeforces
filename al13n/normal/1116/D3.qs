namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Unit {
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
        H(qs[0]);
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        for (v in 0..127) {
//            using ((x, y) = (Qubit[9], Qubit())) {
//                ApplyPauliFromBitString(PauliX, true, IntAsBoolArray(v, 9), x);
//                Solve(x, y);
//                Message($"{IntAsBoolArray(v, 7)} {M(y)}");
//                ResetAll(x);
//                Reset(y);
//            }
//        }
//    }
}