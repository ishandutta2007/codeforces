namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : () {
        body {
            let n = Length(qs);
            H(qs[0]);
            for (i in 1..(n-1)) {
                CNOT(qs[0], qs[i]);
            }
        }
    }

    operation Simulate(n : Int) : Int {
        body {
            mutable measurment = 0;
            using (register = Qubit[n]) {
                Solve(register);
                for (i in 0..(n-1)) {
                    if (M(register[i]) == One) { set measurment = measurment + 1; }
                }
                ResetAll(register);
            }
            return measurment;
        } 
    }
}