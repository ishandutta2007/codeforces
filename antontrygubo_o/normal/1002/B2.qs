namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable checker = 0;
            for (i in 0..Length(qs)-1)
            {
                if (M(qs[i])==One) 
                {
                    set checker = checker+1;
                }
            }
            if (checker==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}