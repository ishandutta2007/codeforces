namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (Inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl  {
        body (...) {
            let len = Length(Inputs);
            using ((tp,qs,tb) = (Qubit[3], Qubit[len], Qubit())) {
                for (i in 0..len - 1){
                    CNOT(Inputs[i],qs[i]);
                }
                for (i in 0..len - 1){
                    CCNOT(tp[0],tp[1],tb);
                    CCNOT(tb, qs[i], tp[2]);
                    CCNOT(tp[0],tp[1],tb);
                    CCNOT(tp[0],qs[i],tp[1]);
                    CNOT(qs[i],tp[0]);
                }
                (ControlledOnInt(len/2,X))(tp,output);
                for (i in 1..len){
                    CNOT(qs[len-i],tp[0]);
                    CCNOT(tp[0],qs[len-i],tp[1]);
                    CCNOT(tp[0],tp[1],tb);
                    CCNOT(tb, qs[len-i], tp[2]);
                    CCNOT(tp[0],tp[1],tb);
                }
                for (i in 0..len - 1){
                    CNOT(Inputs[i],qs[i]);
                }
            }
        }

        adjoint auto;

    }
}