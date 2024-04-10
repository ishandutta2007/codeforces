namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable r = 1;
        using ((a, b) = (Qubit(), Qubit())) {
            unitary([a, b]);
            if (M(b) == One) {
                set r = 0;
                X(b);
            }
        }
        return r;
    }

//    operation IX(a : Qubit[]) : Unit is Adj+Ctl {
//        X(a[1]);
//    }
//    operation CN(a : Qubit[]) : Unit is Adj+Ctl {
//        CNOT(a[0], a[1]);
//    }
//
//    @EntryPoint()
//    operation test() : Unit {
//        let i = Solve(IX);
//        let x = Solve(CN);
//        Message($"{i} {x}");
//    }
}