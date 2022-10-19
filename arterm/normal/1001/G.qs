namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : () {
        body {
            CNOT(x[k], y);
        }
    }

    operation Simulate(n : Int, k : Int) : Int[] {
        body {
            mutable measurment = new Int[n + 1];
            using (register = Qubit[n+1]) {
                for (i in 0..(n-1)) {
                    if (i % 3 == 0) {
                        X(register[i]);
                    }
                }

                Solve(register[0..(n-1)], register[n], k);

                for (i in 0..n) {
                    if (M(register[i]) == One) {
                        set measurment[i] = 1;
                    }
                }
                ResetAll(register);
            }
            return measurment;
        } 
    }
}