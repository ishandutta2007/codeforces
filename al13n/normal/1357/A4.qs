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



    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            Controlled unitary([a], (2.*PI(), b));
            H(a);
            let r = 1 - ToInt(M(a));
            Reset(a);
            return r;
        }
    }

    operation op0(a : Double, q : Qubit) : Unit is Adj+Ctl {
        Rz(a, q);
    }
    operation op1(a : Double, q : Qubit) : Unit is Adj+Ctl {
        R1(a, q);
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    for (w in 0..1) {
    //        for (i in 1..10) {
    //            let r = Solve([op0, op1][w]);
    //            Message($"{w} {r}");
    //        }
    //    }
    //}
}