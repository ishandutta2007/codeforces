namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (x : Qubit[], y : Qubit) : Unit
    {
        using(tmp = Qubit()) {
            CCNOT(x[0],tmp,y); CNOT(x[0],tmp); 
            CCNOT(x[1],tmp,y); CNOT(x[1],tmp); 
            CCNOT(x[2],tmp,y); CNOT(x[2],tmp); 
            CNOT(x[0], tmp);
            CNOT(x[1], tmp);
            CNOT(x[2], tmp);
		}
    }
}