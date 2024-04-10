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


    operation doit(inputs : Qubit[], a : Qubit, b : Qubit) : Unit is Adj+Ctl {
        for (i in 0..2..Length(inputs)-1) {
            CCNOT(inputs[i], a, b);
            CCNOT(inputs[i], b, a);
            CX(inputs[i], b);
        }
        for (i in 1..2..Length(inputs)-1) {
            CX(inputs[i], b);
            CCNOT(inputs[i], b, a);
            CCNOT(inputs[i], a, b);
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using ((a, b) = (Qubit(), Qubit())) {
            doit(inputs, a, b);
            X(a);
            X(b);
            CCNOT(a, b, output);
            X(a);
            X(b);
            Adjoint doit(inputs, a, b);
        }
    }

    operation op0(q : Qubit) : Unit is Adj+Ctl {
        Y(q);
    }
    operation op1(q : Qubit) : Unit is Adj+Ctl {
        X(q);
        Z(q);
    }
    operation op2(q : Qubit) : Unit is Adj+Ctl {
        Y(q);
        Z(q);
        X(q);
        Z(q);
        X(q);
    }
    operation op3(q : Qubit) : Unit is Adj+Ctl {
        Z(q);
        X(q);
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