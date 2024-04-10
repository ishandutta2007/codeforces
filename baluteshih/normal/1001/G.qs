namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : Unit
    {
        body
        {
            CNOT(x[k],y);
        }
    }
}