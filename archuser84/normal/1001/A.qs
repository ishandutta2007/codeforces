namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    
    operation Solve(q : Qubit, sign : Int) : Unit
    {
        if(sign >= 0)
        {
            H(q);  
		}
        else
        {
            X(q);
            H(q);
		}
	}
}