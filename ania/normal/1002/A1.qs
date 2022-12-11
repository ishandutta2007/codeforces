namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            for (i in 0..n-1) {
                H(qs[i]);
            }
        }
    }

    operation Go (n : Int) : Bool {
        body {
            using (qs = Qubit[n]) {
                Solve(qs);
                ResetAll(qs);
            }
            return true;
        }
    }
}