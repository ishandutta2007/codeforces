namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let n = Length(qs);
            mutable ans = 0;
            for (i in 0 .. n - 1)
            {
                let x = M(qs[i]);
                if (x == One)
                {
                    return 1;
                }
            }
            
            return 0;
        }
    }
}