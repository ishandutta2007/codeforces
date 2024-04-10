namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation doit(x : Qubit[], a : Qubit[]) : Unit is Adj {
        let n = Length(x);
        for (q in x) {
            (ControlledOnInt(1, X))([q, a[0]], a[1]);
            (ControlledOnInt(1, X))([q, a[1]], a[0]);
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit is Adj {
        let n = Length(x);
        using (a = Qubit[2]) {
            doit(x, a);
            (ControlledOnInt(0, X))([a[0], a[1]], y);
            Adjoint doit(x, a);
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