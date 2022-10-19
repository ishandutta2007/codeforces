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
 

	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (Q = Qubit[2]){
        
        	H(Q[0]);
        	H(Q[1]);
        	Controlled U([Q[0]],Q[1]);
        	Controlled X([Q[0]],Q[1]);
        	Controlled U([Q[0]],Q[1]);
        	Controlled X([Q[0]],Q[1]);
        	H(Q[0]);
        	DumpMachine("a.txt");
        	let m1 = M(Q[0]);

        	if(m1 == Zero){
        		// 1 ou 3
        		reset(Q[0]);
        		reset(Q[1]);
        		H(Q[0]);
        		H(Q[1]);
        		Controlled U([Q[0]],Q[1]);
        		Controlled X([Q[0]],Q[1]);
        		Controlled Z([Q[0]],Q[1]);
        		H(Q[0]);
        		H(Q[1]);
        		DumpMachine("b.txt");
        		let m2 = M(Q[0]);
        		if(m2 == Zero){
        			set res = 3;
        		}
        		else {
        			set res = 1;
				}
			}

			else {
				reset(Q[0]);
        		reset(Q[1]);
        		H(Q[0]);
        		H(Q[1]);
        		Controlled U([Q[0]],Q[1]);
        		Controlled X([Q[0]],Q[1]);
				Controlled Y([Q[0]],Q[1]);
				Controlled X([Q[0]],Q[1]);
        		H(Q[0]);
        		H(Q[1]);
        		DumpMachine("c.txt");
        		let m2 = M(Q[0]);
        		if(m2 == Zero){
        			set res = 2;
        		}
        		else {
        			set res = 0;
				}			
			}
		reset(Q[0]);
		reset(Q[1]);
		}
	return res;
    }

	

//	 @EntryPoint()
 
    operation main() : Unit {
 
        using ( q = Qubit[4] ){
 
 
 			for(i in 0..50){
			mutable x = Solve(r0);
 			Message($"{x}");
 			set x = Solve(r1);
 			Message($"{x}");
 			set x = Solve(r2);
 			Message($"{x}");
 			set x = Solve(r3);
 			Message($"{x}");
 			}
 			
 
 
			DumpMachine("a.txt");
 
 
 
			ResetAll(q);
 
 
 
		}
 
        
 
    }



}