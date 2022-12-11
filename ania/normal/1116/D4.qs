namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            X(qs[n-1]);
            
            let OpPlus = IntegerIncrementLE(1, _);
            let OpMinus = IntegerIncrementLE(-1, _);
            (ControlledOnInt(1, OpPlus))([qs[n-1]], LittleEndian(qs[0..n-2]));
            (ControlledOnInt(0, OpMinus))([qs[n-1]], LittleEndian(qs[0..n-2]));
            
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