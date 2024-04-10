namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation DoTheThing(x : Qubit, a : Qubit, b : Qubit) : Unit {
        body (...) {
            CCNOT(x,a,b);
            CNOT(x,a);
            using(tmp = Qubit()) {
                CCNOT(a,b,tmp);
                CNOT(tmp,a);
                CNOT(tmp,b);
                X(a); X(b);
                Controlled X([x,a,b],tmp);
                X(a); X(b);
	    	}
    	}
        adjoint auto;
	}

    operation Count(x : Qubit[], a : Qubit, b : Qubit) : Unit {
        body (...) {
            for(q in x) {
                DoTheThing(q, a, b);     
			}
		}
        adjoint auto;
	}

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using((a, b) = (Qubit(), Qubit())) {
                Count(x,a,b);
                (ControlledOnInt(0, X))([a,b],y);
                Adjoint Count(x,a,b);
			}
        }
        adjoint auto;
    }
}