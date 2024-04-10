namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
            mutable pos = 0;
            for (i in 0 .. n - 1)
            {
                if(bits0[i] != bits1[i])
                {
                    set pos = i;
                }
            }
            
            H(qs[pos]);
            
            for(i in 0 .. n - 1)
            {
                if(i != pos)
                {
                    if(bits0[i])
                    {
                        if(bits1[i])
                        {
                            X(qs[i]);
                        }
                        else
                        {
                            if(bits0[pos] == bits0[i])
                            {
                                CNOT(qs[pos], qs[i]);
                            }
                            else
                            {
                                X(qs[i]);
                                CNOT(qs[pos], qs[i]);
                            }
                        }
                    }
                    else
                    {
                        if(bits1[i])
                        {
                            if(bits0[pos] == bits0[i])
                            {
                                CNOT(qs[pos], qs[i]);
                            }
                            else
                            {
                                X(qs[i]);
                                CNOT(qs[pos], qs[i]);
                            }
                        }
                    }
                }
            }
        }
    }
}