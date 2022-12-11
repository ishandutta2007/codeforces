
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            for (i in 1..n-1) {
                CNOT(qs[0], qs[i]);
            }
            H(qs[0]);
            for (i in 1..n-1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }
}