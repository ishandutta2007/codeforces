namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Testing;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(2.0*ArcCos(0.924), q);
            mutable res = -1;
            if (M(q) == One) {
                set res = 1;
            } else {
                set res = 0;
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