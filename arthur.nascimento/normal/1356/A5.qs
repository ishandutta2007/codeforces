namespace Solution {
 
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Primitive;
 	open Microsoft.Quantum.Math;
 
 
	operation reset(x : Qubit) : () {
 
		if(M(x) == One){
 
			X(x);
 
		}
 
	}

	operation IX (q : Qubit[]) : Unit is Adj+Ctl {
		X(q[1]);
	}
	operation CN (q : Qubit[]) : Unit is Adj+Ctl {
		CNOT(q[0],q[1]);
	}
	operation rZ (q : Qubit) : Unit is Adj+Ctl {
		Z(q);
		Rz(4.0 * ArcCos(0.0), q);
	}
 
	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (q = Qubit[2]){
			H(q[0]);
			H(q[1]);
			Controlled U([q[0]],q[1]);
			Controlled Z([q[0]],q[1]);
			H(q[0]);
			if(M(q[0]) == Zero){
				set res = 0;
			}
			else {
				set res = 1;
			}
			reset(q[0]);
			reset(q[1]);
        }
        return res;
    }
	

	

    //@EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){


			H(Q[0]);
			rZ(Q[0]);

			let x = Solve(Z);
			let y = Solve(rZ);
			
			Message($"{x}{y}");

					

			//DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}