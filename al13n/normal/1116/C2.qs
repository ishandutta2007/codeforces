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
        (ControlledOnInt(0, X))([x[0], x[n-1]], a[0]);
        (ControlledOnInt(3, X))([x[0], x[n-1]], a[0]);

        CNOT(a[0], a[1]);
        if (n >= 4) {
            (ControlledOnInt(0, X))([x[0], x[n-2], x[1], x[n-1], a[0]], a[1]);
            (ControlledOnInt(3, X))([x[0], x[n-2], x[1], x[n-1], a[0]], a[1]);
            (ControlledOnInt(12, X))([x[0], x[n-2], x[1], x[n-1], a[0]], a[1]);
            (ControlledOnInt(15, X))([x[0], x[n-2], x[1], x[n-1], a[0]], a[1]);
        }

        CNOT(a[1], a[2]);
        if (n >= 6) {
            (ControlledOnInt(0, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(3, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(12, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(15, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(48, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(51, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(60, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
            (ControlledOnInt(63, X))([x[0], x[n-3], x[1], x[n-2], x[2], x[n-1], a[1]], a[2]);
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit is Adj {
        using (a = Qubit[3]) {
            doit(x, a);
            CNOT(a[2], y);
            Adjoint doit(x, a);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        for (v in 0..127) {
//            using ((x, y) = (Qubit[7], Qubit())) {
//                ApplyPauliFromBitString(PauliX, true, IntAsBoolArray(v, 7), x);
//                Solve(x, y);
//                Message($"{IntAsBoolArray(v, 7)} {M(y)}");
//                ResetAll(x);
//                Reset(y);
//            }
//        }
//    }
}