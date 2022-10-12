namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q1 = Qubit()) {
            using (q2 = Qubit()) {
                X(q1);
                unitary([q1, q2]);
                let res = M(q1);
                let res2 = M(q2);
                if (res2 == One) {
                    Reset(q1);
                    Reset(q2);
                    return 0;
                } else {
                    Reset(q1);
                    Reset(q2);
                    return 1;
                }
            }
        }
    }
}