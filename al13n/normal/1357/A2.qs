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
            let x = M(a);
            let y = M(b);
            ResetAll([a, b]);
            X(b);
            unitary([a, b]);
            let z = M(a);
            ResetAll([a, b]);
            if (x == One and y == One) {
                return 1;
            } elif (x == Zero and y == One) {
                return 3;
            } elif (z == One) {
                return 2;
            } else {
                return 0;
            }
        }
    }

    operation op0(qs : Qubit[]) : Unit is Adj+Ctl {
    }
    operation op1(qs : Qubit[]) : Unit is Adj+Ctl {
        CNOT(qs[0], qs[1]);
    }
    operation op2(qs : Qubit[]) : Unit is Adj+Ctl {
        CNOT(qs[1], qs[0]);
    }
    operation op3(qs : Qubit[]) : Unit is Adj+Ctl {
        SWAP(qs[1], qs[0]);
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