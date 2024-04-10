namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    
    operation Solve (q : Qubit) : Int
    {
        H(q);
        if(M(q) == Zero) {
            return 1;
        } else {
            return -1;
		}
	}
}