namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        (OperationPowCA(QFTLE, p % 4))(inputRegister);
    }
}