namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r = 1;
        using (a = Qubit()) {
            H(a);
            unitary(a);
            unitary(a);
            H(a);
            if (M(a) == Zero) {
                set r = 0;
            } else {
                X(a);
            }
        }
        return r;
    }

//    @EntryPoint()
//    operation test() : Unit {
//        let i = Solve(Z);
//        let x = Solve(S);
//        Message($"{i} {x}");
//    }
}