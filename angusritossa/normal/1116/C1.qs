namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
        	let n = Length(x);
        	if (n != 1)
        	{
        		using (aux = Qubit[n-1]) {

		        	for (i in 0 .. n-2)
    		        {
        		    	CNOT(x[i], aux[i]);
						CNOT(x[i+1], aux[i]);
						X(aux[i]);
	        	    }
    	        	// It is true if at least one of them is true ... i.e. an or
        	    	X(y);
            		(ControlledOnInt(0, X))(aux, y);
            		for (i in n-2 .. -1 .. 0)
    		        {
    		        	X(aux[i]);
						CNOT(x[i+1], aux[i]);
						CNOT(x[i], aux[i]);
	        	    }
	        	}
            }
            X(y);
        }
        adjoint auto;
    }
}