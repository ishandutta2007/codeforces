namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    
    operation Solve(qs : Qubit[]) : Unit
    {
        let N = Length(qs) - 1;
        H(qs[0]);
        for (i in 1..N) {
			CNOT(qs[0], qs[i]);
		}
	}
}