namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : Unit {
        H(qs[0]);
        CNOT(qs[0], qs[1]);
        if (index % 2 == 1) {
            Z(qs[1]);
        }
        if (index >= 2) {
            X(qs[0]);
        }
    }
}