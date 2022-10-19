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


    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            using ( (Q,q) = (Qubit[N],Qubit())){
            	for(a in Q){
					H(a);
            	}
            	X(q);
            	H(q);
            	Uf(Q,q);
            	for(a in Q){
            		H(a);
            	}

				mutable ans = true;
            	
            	for(a in Q){
					if(M(a) == One){
						set ans = false;
					}
            	}

            	for(a in Q){
            		reset(a);
            	}
            	reset(q);

				return ans;
            	
			}
        }
    }







   // @EntryPoint()

    operation main() : Unit {

      //  using ( (Q,q) = (Qubit[3],Qubit()) ){

			

            mutable x = Solve(4,F);
            Message($"F -> {x}");
           // set x = Solve(4,FF);
            Message($"F -> {x}");

            DumpMachine("a.txt");

            

            Message($"oie");

    //    }

        

    }

}