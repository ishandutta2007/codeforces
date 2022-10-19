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
 
	operation Solve (U : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]){
			U(q);
			let x = M(q[1]);
			reset(q[1]);
			if(x == One){
				return 0;
			}
			else {
				return 1;
			}
			
		}
    }
	

	

   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){



			let x = Solve(IX);
			let y = Solve(CN);

			Message($"{x}{y}");

					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}