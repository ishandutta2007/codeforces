namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            let res = M(qs[0]) == Zero ? 0 | 1;
            Reset(qs[0]);
            Reset(qs[1]);
            return res;
        }
    }
}