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



    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            Controlled unitary([a], b);
            Controlled unitary([a], b);
            H(a);
            let x = M(a);
            ResetAll([a, b]);
            H(a);
            Controlled Y([a], b);
            if (x == One) {
                R1(PI()/2., a);
            }
            Controlled unitary([a], b);
            H(a);
            let y = M(a);
            ResetAll([a, b]);
            if (x == One and y == One) {
                return 1;
            } elif (x == One and y == Zero) {
                return 3;
            } elif (x == Zero and y == One) {
                return 2;
            } else {
                return 0;
            }
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