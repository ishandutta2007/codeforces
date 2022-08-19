namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.MachineLearning;

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


    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            H(b);
            CZ(a, b);
            unitary(b);
            CZ(a, b);
            H(a);
            H(b);
            CNOT(b, a);
            let r = MeasureInteger(LittleEndian([a, b]));
            ResetAll([a, b]);
            return r;
        }
    }

    operation op0 (q : Qubit) : Unit is Adj+Ctl {
    }
    operation op1 (q : Qubit) : Unit is Adj+Ctl {
        X(q);
    }
    operation op2 (q : Qubit) : Unit is Adj+Ctl {
        Y(q);
    }
    operation op3 (q : Qubit) : Unit is Adj+Ctl {
        Z(q);
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    for (w in 0..3) {
    //        for (i in 1..10) {
    //            let r = Solve([op0, op1, op2, op3][w]);
    //            Message($"{w} {r}");
    //        }
    //    }
    //}
}