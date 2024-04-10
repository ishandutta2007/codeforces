namespace Solution {
 
 
 
    open Microsoft.Quantum.Canon;
 
    open Microsoft.Quantum.Diagnostics;
 
    open Microsoft.Quantum.Primitive;
 
 
 
	operation reset(x : Qubit) : () {
 
		if(M(x) == One){
 
			X(x);
 
		}
 
	}
 
	operation Solve (qs : Qubit[]) : Unit {
		body {
        mutable ok = 0;
        while(ok == 0){
			using(a = Qubit()){
				reset(qs[0]);
				reset(qs[1]);
				H(qs[0]);
				H(qs[1]);
				(ControlledOnInt(0,X)) (qs,a);
				let res = M(a);
				reset(a);
				if(res == Zero){
					set ok = 1;
				}
			}
        }
        }
    }
	

	

   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){



			Solve(Q);

					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}