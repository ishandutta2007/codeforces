namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



	operation F (Q : Qubit[], q : Qubit) : Unit {

		body {

			X(q);

		}

	}



	operation FF (Q : Qubit[], q : Qubit) : Unit {

		body {

			for(a in Q){

				CNOT(a,q);

			}

		}

	}



	operation reset(Q : Qubit) : () {

		body {

			if(M(Q) == One){

				X(Q);

			}

		}

	}



    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.792699,q);
            if(M(q) == Zero){
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


			mutable x = 0;

			for(i in 1 .. 10000){
				reset(Q[0]);
				H(Q[0]);
				let r = Solve(Q[0]);
				if(r == 0){
					set x += 1;
				}
			}



			DumpMachine("a.txt");

			
			Message($": {x}");
			

			for(q in Q){

				reset(q);

			}



            

            

            

            Message($"oie");

        }

        

    }

}