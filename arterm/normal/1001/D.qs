namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int {
        body {
            mutable measurment = 0;
            H(q);
            if (M(q) == One) {set measurment = -1;} else {set measurment = +1;}
            return measurment;
        }
        
    }

    operation Simulate(index : Int) : Int {
        body {
            mutable measurment = 0;
            using (register = Qubit[1]) {
                let a = register[0];
                if (index == 0) {
                    H(a);
                } else {
                    X(a);
                    H(a);
                }
                set measurment = Solve(a);
                ResetAll(register);
            }
            return measurment;
        } 
    }
}