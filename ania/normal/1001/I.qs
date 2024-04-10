namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable res = true;
            using (qs = Qubit[N]) {
                using (y = Qubit[1]) {
                    for (i in 0..N-1) {
                        H(qs[i]);
                    }
                    H(y[0]);
                    Z(y[0]);
                    Uf(qs, y[0]);
                    for (i in 0..N-1) {
                        H(qs[i]);
                        if (M(qs[i]) == One) { set res = false; }
                    }
                    ResetAll(qs);
                    ResetAll(y);
                }
            }
            return res;
        }
    }

    operation Cons0 (x : Qubit[], y : Qubit) : ()
    {
        body {

        }
    }

    operation Cons1 (x : Qubit[], y : Qubit) : ()
    {
        body {
            X(y);
        }
    }

    operation Sum (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n = Length(x);
            for (i in 0..n-1) {
                CNOT(x[i], y);
            }
        }
    }

    operation Kth0 (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            CNOT(x[0], y);
        }
    }

    operation KthN (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n = Length(x);
            CNOT(x[n-1], y);
        }
    }

    operation Go (n : Int, orac : Int) : Bool {
        body {
            mutable res = false;
            if (orac == 0) {
                let ret = Solve(n, Cons0);
                if (ret) { set res = true; }
            } else {
                if (orac == 1) {
                    let ret = Solve(n, Cons1);
                    if (ret) { set res = true; }
                } else {
                    if (orac == 2) {
                        let ret = Solve(n, Kth0);
                        if (ret==false) { set res = true; }
                    } else {
                        if (orac == 3) {
                            let ret = Solve(n, KthN);
                            if (ret==false) { set res = true; }
                        } else {
                            let ret = Solve(n, Sum);
                            if (ret==false) { set res = true; }
                        }
                    }
                }
            }
            return res;
        }
    }
}