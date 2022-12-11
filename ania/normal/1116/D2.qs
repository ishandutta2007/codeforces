namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            for (i in 1..n-1) {
                for (j in 0..i-1) {
                    (ControlledOnInt(1, H))(qs[i..n-1], qs[j]);
                }
            }
        }
    }
}