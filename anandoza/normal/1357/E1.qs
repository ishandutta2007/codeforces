namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
 
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for (index in 0 .. (p%4)-1) {
            QFTLE(inputRegister);
        }
    }
}