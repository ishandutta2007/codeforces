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




 

	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (Q = Qubit[2]){
        	H(Q[0]);
        	H(Q[1]);
        	Controlled Z([Q[0]],Q[1]);
        	U(Q[1]);
        	Controlled Z([Q[1]],Q[0]);
        	H(Q[0]);
        	H(Q[1]);
        	let x = M(Q[0]);
        	let y = M(Q[1]);
        	if(x == Zero && y == Zero){
        		set res = 0;
        	}
        	if(x == One && y == Zero){
        		set res = 1;
        	}
        	if(x == One && y == One){
        		set res = 2;
        	}
        	if(x == Zero && y == One){
        		set res = 3;
        	}
        	reset(Q[0]);
        	reset(Q[1]);
		}
		return res;
    }

	

	



}