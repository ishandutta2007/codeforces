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
 
	operation Solve (qs : Qubit[]) : Unit {
		body {
        	Ry(2.0 * ArcCos(Sqrt(2.0/3.0)), qs[0]);
        	(ControlledOnInt(0,H)) ([qs[0]],qs[1]);
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