namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    //open Microsoft.Quantum.Arithmetic;
 

    operation my_QFT(qs : Qubit[]) : Unit is Adj+Ctl {
        H(qs[0]);
        Controlled S([qs[1]], qs[0]);
        H(qs[1]);
        SWAP(qs[0], qs[1]);
	}

    operation PhaseEstim(u : Qubit, U : (Qubit => Unit is Ctl)) : Int {
        mutable ans = 0;
        using(qs = Qubit[2]) {
            H(qs[0]); H(qs[1]);
            Controlled U([qs[1]], u); CNOT(qs[1], u);
            Controlled U([qs[0]], u); CNOT(qs[0], u);
            Controlled U([qs[0]], u); CNOT(qs[0], u);
            Adjoint my_QFT(qs);
            set ans = ResultAsInt([M(qs[1])]) + 2*ResultAsInt([M(qs[0])]);
            ResetAll(qs);
		}
        return ans;
	}

    operation Solve (unit : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using(q = Qubit()) {
            X(q);
            set ans = PhaseEstim(q, unit);
            X(q);
	    }
        if(ans==0){return 1;}
        if(ans==1){return 2;}
        if(ans==2){return 3;}
        if(ans==3){return 0;}
        return -1;
	}
}