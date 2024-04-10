namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Reset(q : Qubit) : Unit
    {
        if(M(q) == One) {
            X(q);  
		}
	}

    operation Solve(N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool
    {
        mutable ans = true;
        using((x,y,t) = (Qubit[N], Qubit(), Qubit()))
        {
			ApplyToEach(H, x);
            X(y); H(y);
            Uf(x, y);
			ApplyToEach(H, x);
            for(i in 0..(N-1)) {
                if(M(x[i]) != Zero) {
                    set ans = false;        
				}
			}
            ApplyToEach(Reset, x);
            Reset(y);
            Reset(t);
		}
        return ans;
	}
}