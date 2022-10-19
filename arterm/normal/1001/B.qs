namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : () {
        body {
            let a = qs[0];
            let b = qs[1];
            if (index == 0) {
                H(a);
                CNOT(a, b);
            }

            if (index == 1) {
                X(a);
                H(a);
                CNOT(a, b);
            }

            if (index == 2) {
                H(a);
                CNOT(a, b);
                X(b);
            }

            if (index == 3) {
                X(a);
                H(a);
                CNOT(a, b);
                X(b);
            }
        }
    }

    operation Simulate(index : Int) : Int {
        body {
            mutable measurment = 0;
            using (register = Qubit[2]) {
                let a = register[0];
                let b = register[1];
                Solve(register, index);
                if (M(a) == One) { set measurment = 1; }
                ResetAll(register);
            }
            return measurment;
        } 
    }
}