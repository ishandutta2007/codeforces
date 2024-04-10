namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve(qs : Qubit[], bits : Bool[]) : Unit
    {
        let N = Length(qs) - 1;
        mutable p = -1;
        for (i in 0..N)
        {
            if(bits[i])
            {
                if(p == -1) {
                    H(qs[i]);
                    set p = i;
			    } else {
                    CNOT(qs[p], qs[i]); 
				}
		    }
		}
	}
}