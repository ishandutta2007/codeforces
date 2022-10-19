namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
			let n = Length(qs);
			mutable id = 0;
			for(i in 0..n-1){
			    if(bits0[i] == bits1[i]){
			    }
			    else {
			        set id = i;
			    }
			}
            H(qs[id]);
            for(i in 0..n-1){
                if(i == id){
                }
                else {
                
                    mutable foi = 0;
                    if(bits0[i] == bits0[id]){
                        if(bits1[i] == bits1[id]){
                            CNOT(qs[id],qs[i]);
                            set foi = 1;
                        }
                    }
                    else {
                        if(bits1[i] == bits1[id]){
                        }
                        else {
                            CNOT(qs[id],qs[i]);
                            X(qs[i]);   
                            set foi = 1;
                        }
                    }
                    if(foi == 0){
                        if(bits0[i] == true){
                            X(qs[i]);
                        }
                    }
                
                }
            }
        }
    
    }
}