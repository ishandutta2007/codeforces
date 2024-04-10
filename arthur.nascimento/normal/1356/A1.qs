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

	
 
	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()){
			U(q);
			let x = M(q);
			reset(q);
			if(x == One){
				return 1;
			}
			else {
				return 0;
			}
			
		}
    }
	

	

 //   @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){



			let x = Solve(I);
			let y = Solve(X);

			Message($"{x}{y}");

					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}