namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve(x : Qubit[], y : Qubit, k : Int) : Unit
    {
        CNOT(x[k], y);
	}
}