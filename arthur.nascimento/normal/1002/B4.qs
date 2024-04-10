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



    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            Controlled Z([qs[0]],qs[1]);
            H(qs[1]);
            H(qs[0]);
            mutable res = 0;
            if(M(qs[0]) == Zero){
				set res += 1;
            }
            if(M(qs[1]) == Zero){
            	set res += 2;
            }
            return res;
        }
    }







   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){


			//Z(Q[0]);
			//Z(Q[1]);

			X(Q[0]);

			H(Q[0]);

			H(Q[1]);





			Controlled Z([Q[0]],Q[1]);



			DumpMachine("a.txt");

			let x = Solve(Q);
			Message($": {x}");
			

			for(q in Q){

				reset(q);

			}



            

            

            

            Message($"oie");

        }

        

    }

}