namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);   		
            let res = ResultAsInt([M(qs[0]); M(qs[1])]);
            if (res==3) {return 0;}
            elif (res==2) {return 2;}
            elif (res==1) {return 1;}
            else {return 3;}
        }
    }
}