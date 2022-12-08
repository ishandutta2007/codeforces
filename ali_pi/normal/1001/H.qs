namespace Solution{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Solve(x : Qubit[], y : Qubit):(){
		body{
			ApplyToEachCA(CNOT(_,y),x);
		}
	}
}