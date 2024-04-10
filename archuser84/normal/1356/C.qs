namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Unit {
        H(qs[0]);
        Controlled H([qs[0]], qs[1]);
        if(M(qs[1]) == One) {
            ResetAll(qs);
            Solve(qs);
		}
        else {
            X(qs[0]);
            Controlled H([qs[0]], qs[1]);
            X(qs[0]); CNOT(qs[0], qs[1]); X(qs[0]);
		}
    }
}