namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Math;



	operation reset(x : Qubit) : () {

		if(M(x) == One){

			X(x);

		}

	}

	operation f(qs : Qubit[]) : () {
		body {
			Ry(2.0 * ArcCos(1.0 / Sqrt(3.0)),qs[0]);
			Controlled H([qs[0]],qs[1]);
			X(qs[0]);
			(ControlledOnInt(0,X)) ([qs[0],qs[1]], qs[2]);
			R1(4.0 * ArcCos(0.0) / 3.0, qs[1]);
			R1(8.0 * ArcCos(0.0) / 3.0, qs[2]);
		}
		adjoint auto;
	}

	operation Solve (qs : Qubit[]) : Int {
		Adjoint f(qs);
        for(i in 0..2){
        	if(M(qs[i]) == One){
        		return 1;
        	}
		}
        return 0;	
    }
	

   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[3] ){


			
			let x = Solve(Q);
					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}

			

            

            Message($"oie {x}");

        }

        

    }

}