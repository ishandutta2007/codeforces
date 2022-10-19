namespace Solution {

 

    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;

 	open Microsoft.Quantum.Math;

	open Microsoft.Quantum.Convert;
		open Microsoft.Quantum.Arithmetic;


 

	operation reset(x : Qubit) : () {

 		if(M(x) == One){

 			X(x);

 		}

	}



	operation pot(a : Int, b : Int) : Int {

		mutable ret = 1;

		for(i in 1..b){

			set ret *= a;

		}

		return ret;

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



	operation sum(x : Qubit[], y : Qubit[], carry : Qubit) :  Unit {

		body {

			let n = Length(x);

			if(n > 0){

				CNOT(carry,x[0]);

				CNOT(carry,y[0]);

				Controlled X([x[0],y[0]],carry);

				sum(x[1..n-1],y[1..n-1],carry);

				Controlled X([x[0],y[0]],carry);

				CNOT(carry,x[0]);

				CNOT(x[0],y[0]);

			}

		}

		controlled auto;

		adjoint auto;

	}



	operation rec(pos : Int, n : Int, soma : Int, Q : Qubit[], res : Qubit) : Unit is Adj+Ctl {



		if(pos < n){

			rec(pos+1,n,soma+1,Q,res);

			X(Q[pos]);

		//	Message($"flip {pos}");

			rec(pos+1,n,soma-1,Q,res);

			X(Q[pos]);

	//		Message($"flip {pos}");

		}

		else {

			if(soma == 0){

		//		Message("check");

				Controlled X(Q,res);

			}

		}

	

	}

	operation incc (register : LittleEndian) : Unit is Adj+Ctl {
		let n=Length(register!);
		if(n>0) {
		Controlled incc(register![0..0], LittleEndian(register![1..n-1]));
		X(register![0]);
		}
	}

 

	operation Solve (Q : Qubit[], res : Qubit) : Unit is Adj+Ctl {

        using (aux = Qubit[3]){
        	let n = Length(Q);
        	within {
				for(i in 0..n-1){
					Controlled incc ([Q[i]],LittleEndian(aux));
				}
			} apply {
				(ControlledOnInt(n/2,X)) (aux,res);
			}	
        }

    }

	

	

   // @EntryPoint()

    operation main() : Unit {

        using ( q = Qubit[7] ){



			for(i in 0..5){

				H(q[i]);

			}

			

			Solve(q[0..5],q[6]);



			DumpMachine("a.txt");



			ResetAll(q);



		}

        

    }

}