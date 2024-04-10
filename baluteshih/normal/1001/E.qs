namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable flag=false;
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            if(M(qs[1])==One)
            {
                set flag = true;
            }
            if(M(qs[0])==Zero)
            {
                if(flag==true)
                {
                    return 2;
                }
                return 0;
            }
            if(flag==true)
            {
                return 3;
            }
            return 1;
        }
    }
}