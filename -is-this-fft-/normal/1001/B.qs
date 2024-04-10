namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : () {
        body {
             H(qs[0]);
             CNOT(qs[0], qs[1]);
             if (index == 1 || index == 3) {
                Z(qs[1]);
             }
             if (index == 2 || index == 3) {
                X(qs[1]);
             }
        }
    }
}