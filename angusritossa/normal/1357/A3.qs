namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            X(q);
            unitary(q);
            X(q);
            unitary(q);
            let res = M(q) == Zero ? 1 | 0;
            Reset(q);
            return res;
        }
    }
}