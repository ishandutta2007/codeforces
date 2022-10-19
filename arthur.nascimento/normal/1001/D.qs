namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let x = M(q);
            if(x == Zero){
				return 1;
			}
			else {
				return -1;
			}
        }
    }
    
}