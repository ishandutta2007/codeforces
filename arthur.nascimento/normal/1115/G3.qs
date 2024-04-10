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

	operation genEq(pos : Int, n : Int, cont : Int, Q : Qubit[], states : Int[], p2 : Int) : Unit {
		if(pos == n || Length(states) == 0){
			return ();
		}
		mutable l0 = new Int[0];
		mutable l1 = new Int[0];
		for(s in states){
			if(s%2 == 0){
				set l0 = l0 + [s/2];
			}
			else {
				set l1 = l1 + [s/2];
			}
		}
		let a = Length(l0);
		let b = Length(l1);
		let theta = 2.0 * ArcCos(Sqrt(IntAsDouble(a)/(IntAsDouble(a+b))));
		(ControlledOnInt(cont,Ry)) (Q[0..pos-1],(theta,Q[pos]));
		
		genEq(pos+1,n,cont,Q,l0,2*p2);
		genEq(pos+1,n,cont+p2,Q,l1,2*p2);
	}

 

	operation Solve (qs : Qubit[]) : () {

        body (...) {
        	let N = Length(qs);
			mutable s = new Int[0];
			mutable x = 1;
			for(i in 0 .. N-1){
				set s = s + [x];
				set x = 2*x;
			}
		
        	genEq(0,N,0,qs,s,1);

        }

       

    }

	

	

    //@EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[5] ){


			Solve(Q);


			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}