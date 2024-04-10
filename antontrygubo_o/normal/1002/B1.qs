namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable checker = false;
            for (i in 0..Length(qs)-1)
            {
                if (M(qs[i])==One) 
                {
                    set checker = true;
                }
            }
            if (checker==true)
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