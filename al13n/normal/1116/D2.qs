namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Unit {
        for (i in Length(qs)-1..-1..0) {
            for (j in 0..i-1) {
                (ControlledOnInt(1, H))(qs[i..Length(qs)-1], qs[j]);
            }
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