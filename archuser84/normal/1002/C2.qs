namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve(q : Qubit) : Int
    {
        let x = RandomInt(2);
        if(x == 0)
        {
            if(M(q) == One){
                return 1;
		    }
            return -1;
		}
        H(q);
        if(M(q) == One){
            return 0;
        }
        return -1;
	}
}