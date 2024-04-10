namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit()) {
            unitary(q);
            X(q);
            Adjoint unitary(q);
            
            let res = M(q);
            if (res == One) {
                set ans = 1;
            }
            
            Reset(q);
        }
        return ans;
    }

    operation F0(x : Qubit) : Unit is Adj+Ctl {
        H(x);
    }
    operation F1(x : Qubit) : Unit is Adj+Ctl {
        X(x);
    }
    
    operation RunQsharp () : Int {
        return Solve(F0) + 10 * Solve(F1);
    }
}