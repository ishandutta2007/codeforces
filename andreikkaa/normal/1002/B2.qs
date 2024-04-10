namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let n = Length(qs);
            mutable a0 = false;
            mutable a1 = false;
            for (i in 0 .. n - 1)
            {
                let x = M(qs[i]);
                if (x == One)
                {
                    set a1 = true;
                }
                else
                {
                    set a0 = true;
                }
            }
            
            if(a0)
            {
                if(a1)
                {
                    return 1;
                }
            }
            return 0;
        }
    }
}