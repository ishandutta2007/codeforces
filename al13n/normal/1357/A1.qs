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



    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((a, b) = (Qubit(), Qubit())) {
            X(a);
            unitary([a, b]);
            let r = M(b);
            ResetAll([a, b]);
            return 1 - ToInt(r);
        }
    }

    operation op(qs : Qubit[]) : Unit is Adj+Ctl {
        CNOT(qs[1], qs[0]);
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    for (i in 1..10) {
    //        let r = Solve(op);
    //        Message($"{r}");
    //    }
    //}
}