namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;


    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable a0 = 1;
            mutable a1 = 1;
            for(i in 0 .. Length(qs)-1){
				mutable y = M(qs[i]);
				mutable x = (y == One);
				if(x != bits0[i]){
					set a0 = 0;
				}
				if(x != bits1[i]){
					set a1 = 0;
				}
            }
            if(a0 > 0){
				return 0;
            }
            return 1;
        }
    }
    
}