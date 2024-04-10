namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            mutable res = M(qs[0]) == Zero ? 0 | 1;
            Reset(qs[0]);
            Reset(qs[1]);
            if (res == 0) {
                // is I or CNOT 1 2
                X(qs[0]);
                unitary(qs);
                set res = M(qs[1]) == Zero ? 0 | 1;
            } else {
                // Is CNOT 2 1 or swap
                X(qs[0]);
                X(qs[1]);
                unitary(qs);
                set res = M(qs[0]) == Zero ? 2 | 3;
            }
            Reset(qs[0]);
            Reset(qs[1]);
            return res;
        }
    }
}