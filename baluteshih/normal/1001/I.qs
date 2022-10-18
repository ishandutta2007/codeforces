namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable flag=true;
            using(qs = Qubit[N])
            {
                using(q = Qubit())
                {
                    X(q);H(q);
                    for(i in 0..N-1)
                    {
                        H(qs[i]);
                    }
                    Uf(qs,q);
                    for(i in 0..N-1)
                    {
                        H(qs[i]);
                        if(M(qs[i])==One)
                        {
                            set flag = false;
                        }
                    }
                    Reset(q);
                    ResetAll(qs);
                }
            }
            return flag;
        }
    }
}