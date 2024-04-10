namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
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
            
            let OpPlus2 = IntegerIncrementLE(2, _);
            let OpMinus2 = IntegerIncrementLE(-2, _);
            let OpMinus1 = IntegerIncrementLE(-1, _);
            
            OpMinus2(LittleEndian(qs));
            (ControlledOnInt(0, OpMinus1))([qs[n-1]], LittleEndian(qs[0..n-2]));
            OpPlus2(LittleEndian(qs));
            
            (ControlledOnInt(0, H))(qs[1..2], qs[0]);
            (ControlledOnInt(3, H))(qs[1..2], qs[0]);
            
            
        }
    }
}