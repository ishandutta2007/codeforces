namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Oracle (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            //bx + 1 - b - x + bx  = 1 + b + x
			let N = Length(x);
			for(i in 0..N-1)
			{
				//X(y);
				CNOT(x[i], y);
			}
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
			mutable ret = new Int[N];
			for(i in 0..N-1)
			{
				set ret[i] = 1;
			}
            using(qubit = Qubit[N+1])
			{
				let m = qubit[0..N-1];
				let s = qubit[N];
				Uf(m, s);
				if(M(s) == One)
				{
					set ret[0] = 0;
                }
				ResetAll(qubit);
			}
			return ret;
        }
    }
}