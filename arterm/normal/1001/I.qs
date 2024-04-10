namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation fun(x : Qubit[], y : Qubit) : () {
        body {
            CNOT(x[0], y);
        }
    }

    operation one(x : Qubit[], y : Qubit) : () {
        body {
            X(y);
        }
    }

    operation Solve (n : Int, f : ((Qubit[], Qubit) => ())) : Bool {
        body {
            mutable measurment = true;
            using (x = Qubit[n]) {
                using (reg = Qubit[1]) {
                    let y = reg[0];
                    X(y); H(y);
                    for (i in 0..(n-1)) { H(x[i]); }
                    f(x, y);
                    for (i in 0..(n-1)) { H(x[i]); }

                    for (i in 0..(n-1)) {
                        if (M(x[i]) == One) {
                            set measurment = false;
                        }
                    }
                    ResetAll(reg);
                }
                ResetAll(x);
            }
            return measurment;
        }
    }

    operation Simulate(n : Int) : Bool {
        body {
            mutable measurment = false;
            set measurment = Solve(n, one);
            return measurment;
        } 
    }
}