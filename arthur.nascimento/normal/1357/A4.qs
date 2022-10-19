namespace Solution {

 

    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;

 	open Microsoft.Quantum.Math;

	open Microsoft.Quantum.Convert;



	operation reset(x : Qubit) : () {

 		if(M(x) == One){

 			X(x);

 		}

	}



	operation phase(q : Qubit, i : Int, Re : Double, Im : Double) : Unit {

		body {

			if(i == 0){

				X(q);

			}

			if(Im > 0.0){

				R1(ArcCos(Re),q);

			}

			else {

				R1(-ArcCos(Re),q);

			}

			if(i == 0){

				X(q);

			}

		}

		controlled auto;

		adjoint auto;

	}



	operation r0 (q : Qubit) : Unit is Adj+Ctl {

		Y(q);



	}

	operation r1 (q : Qubit) : Unit is Adj+Ctl {

		Z(q);

		X(q);



		X(q);

		Z(q);

		X(q);

		Z(q);

		

	}

	operation r2 (q : Qubit) : Unit is Adj+Ctl {

		Y(q);



		X(q);

		Z(q);

		X(q);

		Z(q);

		

		//Y(q);

	}

	operation r3 (q : Qubit) : Unit is Adj+Ctl {



		Z(q);

		X(q);

	}

 

	operation Solve (U : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (q = Qubit[2]){
        	H(q[0]);
 			H(q[1]);

 			Controlled U ([q[0]],(4.0 * ArcCos(0.0), q[1]));
 			

 			H(q[0]);
 			H(q[1]);

 			if(M(q[0]) == M(q[1])){
 				set res = 1;
 			}
 			reset(q[0]);
 			reset(q[1]);
 		}
 		return res;
    }

	

//	 @EntryPoint()

 

    operation main() : Unit {

 

        using ( q = Qubit[2] ){

 

 			H(q[0]);
 			H(q[1]);

 			Controlled R1 ([q[0]],(4.0 * ArcCos(0.0), q[1]));
 			

 			H(q[0]);
 			H(q[1]);

 			

 

 

			DumpMachine("a.txt");

 

 

 

			ResetAll(q);

 

 

 

		}

 

        

 

    }



}