namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve(qs : Qubit[]) : Int
    {
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        let a = M(qs[0]);
        let b = M(qs[1]);
        if(a == Zero and b == Zero) {
            return 0;  
		}
        if(a == One and b == Zero) {
            return 1;  
		}
        if(a == Zero and b == One) {
            return 2;  
		}
        if(a == One and b == One) {
            return 3;  
		}
        return -1;
	}
}