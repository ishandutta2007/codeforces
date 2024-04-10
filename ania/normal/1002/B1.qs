namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable res = 0;
            using (y = Qubit[1]) {
                let n = Length(qs);
                for (i in 0..n-1) {
                    CNOT(qs[i], y[0]);
                }
                if (M(y[0]) == One) {
                    set res = 1;
                }
                ResetAll(y);
            }
            return res;
        }
    }

}