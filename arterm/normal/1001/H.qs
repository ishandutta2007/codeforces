namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(x : Qubit[], y : Qubit) : () {
        body {
            ApplyToEach(CNOT(_, y), x);
        }
    }

    operation Simulate(n : Int) : Bool {
        body {
            mutable measurment = false;
            return measurment;
        } 
    }
}