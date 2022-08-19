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



    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        let rep = Round(PI()/theta);
        let cnt = 300/rep;
        mutable res = 0;
        using ((a) = (Qubit())) {
            for (i in 1..cnt) {
                for (j in 1..rep) {
                    unitary(a);
                }
                if (M(a) == One) {
                    set res += 1;
                    X(a);
                }
            }
        }
        return BoolToInt(res*2>cnt);
    }

    operation op0(q : Qubit) : Unit is Adj+Ctl {
        Rz(PI()*0.66, q);
    }
    operation op1(q : Qubit) : Unit is Adj+Ctl {
        Ry(PI()*0.66, q);
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    for (w in 0..1) {
    //        for (i in 1..10) {
    //            let r = Solve(PI()*.66, [op0, op1][w]);
    //            Message($"{w} {r}");
    //        }
    //    }
    //}
}