namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : () {
        body {
            if (sign == -1) { X(q); }
            H(q); 
        }
    }

    operation Simulate(sign : Int) : Int {
        body {
            mutable measurment = 0;
            using (register = Qubit[1]) {
                let q = register[0];
                Solve(q, sign);
                if (M(q) == One) { set measurment = 1; }
                ResetAll(register);
            }
            return measurment;
        } 
    }
}