namespace Solution {
    open Microsoft.Quantum.Primitive;
 
    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            Reset(q);
            if (sign == -1) {
                X(q);
            }
            H(q);
        }
    }
}