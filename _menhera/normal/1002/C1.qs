namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(10.2, q);
            if(M(q) == One)
            {
                return 0;
            }
            else
            {
                return 1;
            }
            // your code here
        }
    }
}