namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    
    operation Solve(qs : Qubit[], index : Int) : Unit
    {
        if(index == 0) {
            H(qs[0]);
            CNOT(qs[0],qs[1]);
		}
        if(index == 1) {
            X(qs[0]);
            H(qs[0]);
            CNOT(qs[0],qs[1]);
		}
        if(index == 2) {
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            X(qs[1]);
		}
        if(index == 3) {
            X(qs[0]);
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            X(qs[1]);
		}
	}
}