namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[]) : Int {
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        return ResultArrayAsInt(MultiM(qs));
    }
}