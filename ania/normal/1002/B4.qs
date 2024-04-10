namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let x0 = M(qs[0]);
            let x1 = M(qs[1]);
            mutable res = 0;
            if (x0 == One) { set res = res + 1; }
            if (x1 == One) { set res = res + 2; }
            if (res == 0) {
                set res = 3;
            } else {
                if (res == 3) {
                    set res = 0;
                }
            }
            return res;
        }
    }

    operation Go (n : Int) : Bool {
        body {
            mutable res = false;
            using (qi = Qubit[2]) {
                if (n%2 == 1) {
                    X(qi[1]);
                }
                if (n>1) {
                    X(qi[0]);
                }
                H(qi[0]);
                H(qi[1]);
                let cur = Solve(qi);
                if (cur == n) { set res = true; }
                ResetAll(qi);
            }
            return res;
        }
    }

}