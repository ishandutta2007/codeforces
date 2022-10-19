namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Par(x : Qubit[], y : Qubit) : Unit
    {
        for (i in 0..(Length(x) - 1)) {
            CNOT(x[i], y);
	    }
	}

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let N = Length(qs);
        for(i in 0..N-2){H(qs[i]);}
        Par(qs[0..N-2],qs[N-1]);
        if(parity==1){X(qs[N-1]);}
    }
}