namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
        	for(a in x){
        		CNOT(a,y);
        	}
        }
    }
    
}