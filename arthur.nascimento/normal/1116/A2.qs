namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



	operation reset(x : Qubit) : () {

		if(M(x) == One){

			X(x);

		}

	}

	operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        let n = Length(bits[0]);
        using(aux = Qubit[2]){
			H(aux[0]);
			H(aux[1]);
			for(i in 0 .. 3){
				for(j in 0 .. n-1){
					if(bits[i][j] == true){
						(ControlledOnInt(i,X)) (aux,qs[j]);
					}
				}
			}
			for(i in 0 .. 3){
				if(i%2 == 1){
					(ControlledOnBitString(bits[i],X)) (qs,aux[0]);
				}
				if(i >= 2){
					(ControlledOnBitString(bits[i],X)) (qs,aux[1]);
				}
			}
        }
    }
	

   // @EntryPoint()

    operation main() : Unit {

        using ( Q = Qubit[3] ){


			mutable mat = new Bool[][4];
			set mat w/= 0 <- [false,false,false];
			set mat w/= 1 <- [false,true,false];
			set mat w/= 2 <- [true,false,true];
			set mat w/= 3 <- [true,true,false];
			Solve(Q,mat);
					

			DumpMachine("a.txt");



			for(q in Q){

				reset(q);

			}

			

            

            Message($"oie");

        }

        

    }

}