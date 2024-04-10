namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation OR(x : Qubit[], y : Qubit) : Unit {
        body (...) {
            (ControlledOnInt(0, X))(x, y);
            X(y);
	    }
        adjoint auto;
	}

    operation P(p : Int, x : Qubit[], y : Qubit) : Unit {
        body (...) {
            for(i in 0..p-1) {
                for(j in i+p..p..Length(x)-1) {
                    CNOT(x[i],x[j]);     
		    	}  
	    	}
            (ControlledOnInt(0, X))(x[p..Length(x)-1], y);
            for(i in 0..p-1) {
                for(j in i+p..p..Length(x)-1) {
                    CNOT(x[i],x[j]);     
		    	}  
	    	}
    	}
        adjoint auto;
	}

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using(tmp = Qubit[Length(x)-1]) {
                for(p in 1..Length(x)-1) {
                    P(p, x, tmp[p-1]);
			    }
                OR(tmp, y);
                for(p in 1..Length(x)-1) {
                    Adjoint P(p, x, tmp[p-1]);
			    }
		    }
        }
        adjoint auto;
    }
}