namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve(x : Qubit[], y : Qubit, b : Int[]) : Unit
    {
        let N = Length(x) - 1;
        for (i in 0..N)
        {
            if(b[i] == 1) {
                CNOT(x[i], y);     
			}  
		}
	}
}