namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Testing;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            let x = RandomInt(2);
            mutable res = -1;
            if (x == 1) {
                H(q);
                if (M(q) == One) {
                    set res = 0;
                }
            } else {
                if (M(q) == One) {
                    set res = 1;
                }
            }
            return res;
        }
    }

    operation Go (id : Int) : Int {
        body {
            mutable ret = 0;
            using (x = Qubit[1]) {
                if (id == 1) {
                    H(x[0]);
                }
                set ret = Solve(x[0]);
                ResetAll(x);
            }
            return ret;
        }
    }
}