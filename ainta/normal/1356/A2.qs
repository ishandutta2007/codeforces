namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            mutable t = M(q);
            Set(Zero, q);
            return t == Zero ? 0 | 1;
        }
    }

}