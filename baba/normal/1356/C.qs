namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
            using(ac = Qubit()) {
        repeat {
                ResetAll(qs);
                Reset(ac);
                H(qs[0]);
                H(qs[1]);
                Controlled X(qs, ac);
                X(qs[0]);
                X(qs[1]);
                let res = M(ac);
        }
        until (res == Zero);
                Reset(ac);
            }
    }
}