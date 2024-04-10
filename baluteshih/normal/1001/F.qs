namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
            for(i in 0..n-1)
            {
                if(M(qs[i])==Zero)
                {
                    if(bits0[i]==true)
                    {
                        return 1;
                    }
                    elif(bits1[i]==true)
                    {
                        return 0;
                    }
                }
                else
                {
                    if(bits0[i]==false)
                    {
                        return 1;
                    }
                    elif(bits1[i]==false)
                    {
                        return 0;
                    }
                }
            }
            return 0;
        }
    }
}