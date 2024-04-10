namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let n = Length(bits);
            mutable first = -1;
            for (i in 0..n-1)
            {
                if (bits[i]==true)
                {
                    if (first==-1)
                    {
                        set first = i;
                        H(qs[i]);
                    }
                    else
                    {
                        CNOT(qs[first], qs[i]);
                    }
                }
            }
        }
    }
}