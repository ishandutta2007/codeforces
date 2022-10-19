namespace Solution {

 

    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;

 	open Microsoft.Quantum.Math;

 	open Microsoft.Quantum.Arithmetic;
 	open Microsoft.Quantum.Convert;

 

 

	operation reset(x : Qubit) : () {

 

		if(M(x) == One){

 

			X(x);

 

		}

 

	}





	operation Solve (x : Qubit[], y : Qubit) : Unit {

        body (...) {

        	using(count = Qubit[2]){

            	let n = Length(x);


            	within {
					for(q in x){
						Controlled X ([q,count[0]],count[1]);
						Controlled X([q],count[0]);
						using (aux = Qubit()){
							Controlled X ([q,count[0],count[1]],aux);
							
							Controlled X ([q,aux],count[0]);
							Controlled X ([q,aux],count[1]);
							X(count[0]);
							X(count[1]);
							Controlled X ([q,count[0],count[1]],aux);
							X(count[0]);
							X(count[1]);
						}
					}
            	} apply {
            		X(count[0]);
					X(count[1]);
            		Controlled X (count,y);
            		X(count[0]);
					X(count[1]);
				}

			}

        }

        adjoint auto;

    }

	

 

	

 

//    @EntryPoint()

 

    operation main() : Unit {

 

        using ( (Q,y) = (Qubit[6 ],Qubit()) ){



			for(q in Q){

				H(q);

			}




			Solve(Q,y);

			DumpMachine("q.txt");

			

			for(q in Q){ 

				reset(q);

			}

			reset(y);

 

        }       

 

    }

 

}