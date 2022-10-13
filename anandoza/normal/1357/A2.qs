namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q1 = Qubit()) {
            using (q2 = Qubit()) {
                X(q1);
                unitary([q1, q2]);
                let res = M(q1);
                let res2 = M(q2);
                if (res == One and res2 == One) {
                    set ans = 1;
                } elif (res == Zero and res2 == One) {
                    set ans = 3;
                } else {
                    set ans = 2;
                }
                Reset(q1);
                Reset(q2);
                X(q1);
                X(q2);
                unitary([q1, q2]);
                let res3 = M(q1);
                let res4 = M(q2);
                if (ans == 2 and res3 == One and res4 == One) {
                    set ans = 0;
                }
                Reset(q1);
                Reset(q2);
            }
        }
        return ans;
    }

    operation F0(x : Qubit[]) : Unit is Adj+Ctl {
        
    }
    operation F1(x : Qubit[]) : Unit is Adj+Ctl {
        CNOT(x[0], x[1]);
    }
    operation F2(x : Qubit[]) : Unit is Adj+Ctl {
        CNOT(x[1], x[0]);
    }
    operation F3(x : Qubit[]) : Unit is Adj+Ctl {
        SWAP(x[0], x[1]);
    }
    
    operation RunQsharp () : Int {
        return 1000 * Solve(F0) + 100 * Solve(F1) + 10 * Solve(F2) + Solve(F3);
    }
}