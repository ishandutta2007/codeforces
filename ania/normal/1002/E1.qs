namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable res = new Int[N];
            for (i in 0..N-1) {
                set res[i] = 0;
            }
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
                        if (M(qs[i]) == One) { set res[i] = 1; }
                    }

                    ResetAll(qs);
                    ResetAll(y);
                }
            }
            return res;
        }
    }


    operation OracB (b : Int[], x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n = Length(x);
            for (i in 0..n-1) {
                if (b[i] == 1) {
                
                    CNOT(x[i], y);
                }
            }
        }
    }

    operation Go (n : Int, b : Int) : Bool {
        body {
            mutable bi = new Int[n];
            mutable bb = b;
            mutable res = true;
                for (i in 0..n-1) {
                    set bi[i] = bb%2;
                    set bb = bb/2;
                }
                let oracc = OracB(bi, _, _);
                let ret = Solve(n, oracc);
                for (i in 0..n-1) {
                    if (ret[i] != bi[i]) {
                        set res = false;
                    }
                }
                
            return res;
        }
    }
}