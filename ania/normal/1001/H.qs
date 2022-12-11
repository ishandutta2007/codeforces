namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n = Length(x);
            for (i in 0..n-1) {
                CNOT(x[i], y);
            }
        }
    }

    operation Go (n : Int, mask : Int) : Bool {
        body {
            mutable m = mask;
            mutable res = false;
            mutable ok = 0;
            using (qi = Qubit[n]) {
                for (i in 0..n-1) {
                    if (m%2==1) {
                        X(qi[i]);
                        set ok = 1-ok;
                    }
                }
                using (y = Qubit[1]) {
                    Solve(qi, y[0]);
                    mutable ret = false;
                    if (M(y[0]) == One) { set ret = true; }
                    if ((ok==1) == ret) { set res = true; }
                    ResetAll(y);
                }
                ResetAll(qi);
            }
            return res;
        }
    }
}