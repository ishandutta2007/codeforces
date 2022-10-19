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
            let x = Random([0.5,0.5]);
			if(x == 0){
				H(q);
				if(M(q) == One){
					return 0;
				}
				else {
					return -1;
				}
			}
			else {
				if(M(q) == One){
					return 1;
				}
				else {
					return -1;
				}
			}
            return 0;
        }
    }







   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[2] ){


			mutable x = 0;
			mutable y = 0;

			for(i in 1 .. 10000){
				reset(Q[0]);
				H(Q[0]);
				let r = Solve(Q[0]);
				if(r == 0){
					set x += 1;
				}
				if(r == -1){
					set y += 1;
				}
			}



			DumpMachine("a.txt");

			
			Message($"0 -> {x},  -1 -> {y}");
			

			for(q in Q){

				reset(q);

			}



            

            

            

            Message($"oie");

        }

        

    }

}