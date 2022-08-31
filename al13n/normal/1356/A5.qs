namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r = 0;
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            Controlled unitary([a], b);
            H(a);
            if (M(a) == One) {
                set r = 1;
                X(a);
            }
        }
        return r;
    }

//    operation MZ(a : Qubit) : Unit is Adj+Ctl {
//        X(a);
//        Z(a);
//        X(a);
//    }
//
//    @EntryPoint()
//    operation test() : Unit {
//        let i = Solve(Z);
//        let x = Solve(MZ);
//        Message($"{i} {x}");
//    }
}