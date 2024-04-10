namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary(qs[0..0], qs[1]);
            H(qs[0]);
            mutable tp = M(qs[0]);
            ResetAll(qs);
            return tp == Zero ? 0 | 1;
        }
    }

}