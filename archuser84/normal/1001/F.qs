namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation toBool(x : Result) : Bool
    {
        if(x == One) {
            return true;
		} else {
            return false;  
		}

	}

    operation Solve(qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        let N = Length(qs) - 1;
        for (i in 0..N)
        {
		    if(toBool(M(qs[i])) != bits0[i]) {
                return 1;
			}
	    }
        return 0;
	}
}