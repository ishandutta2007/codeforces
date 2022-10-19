namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve(qs : Qubit[]) : Int
    {
        mutable ans = 0;
        for (q in qs)
        {
            if(M(q) == One){
                set ans = 1;     
			}  
		}
        return ans;
	}
}