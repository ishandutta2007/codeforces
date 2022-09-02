namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
            mutable first = -1;
            
            for (i in 0..n-1)
            {
                if (bits0[i]==bits1[i])
                {
                    if (bits0[i]==true)
                    {
                        X(qs[i]);
                    }
                }
                else
                {
                    if (first==-1)
                    {
                        set first = i;
                        H(qs[first]);
                    }
                    else
                    {
                        CNOT(qs[first], qs[i]);
                        if (bits0[i]!=bits0[first])
                        {
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }
}