namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;

    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Arithmetic;



	operation reset(x : Qubit) : () {
		if(M(x) == One){
			X(x);
		} 
	}



	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {

	   let Q = register!;
	   let n = Length(Q);
       using(carry = Qubit[n+1]){
       		X(carry[0]);
			for(i in 0 .. n-1){
				Controlled X([carry[i],Q[i]],carry[i+1]);
				CNOT(carry[i],Q[i]);
			}
			for(i in 0 .. n-1){
				(ControlledOnInt(1,X)) ([carry[n-i-1],Q[n-i-1]] , carry[n-i]);
			}
			X(carry[0]);
       }

       
    }

	

    //@EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[3] ){



			H(Q[0]);

			Solve(LittleEndian(Q));

					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}



			

        }

        

    }

}