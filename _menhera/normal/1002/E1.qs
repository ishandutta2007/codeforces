namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Oracle (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let N = Length(x);
            for(i in 0..N-1)
			{
				if(i%2 == 1)
				{
					CNOT(x[i], y);
				}
			}
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
			mutable ret = new Int[N];
            using(qubit = Qubit[N+1])
			{
                let m = qubit[0..N-1];
				let s = qubit[N];
                for(i in 0..N-1)
                {
                    H(qubit[i]);
                }
                X(s);
                H(s);
				
                Uf(m, s);
                for(i in 0..N-1)
                {
                    H(qubit[i]);
                    if(M(qubit[i]) == Zero)
                    {
                        set ret[i] = 0;
                    }
                    else
                    {
                        set ret[i] = 1;
                    }
                }
                ResetAll(qubit);
			}
			return ret;
        }
    }
}