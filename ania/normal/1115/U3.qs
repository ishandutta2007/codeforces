namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            for (i in 1..n-1) {
                CNOT(x[n-i-1], x[n-i]);
            }
            Controlled X(x[1..n-1], y);
            for (i in 0..n-2) {
                CNOT(x[i], x[i+1]);
            }
        }
        adjoint auto;
    }
}