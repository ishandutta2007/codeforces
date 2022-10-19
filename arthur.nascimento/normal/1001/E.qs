namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            mutable ret = 0;
            if(M(qs[0]) == One){
				set ret += 1;
            }
            if(M(qs[1]) == One){
				set ret += 2;
            }
            return ret;
        }
    }
    
}