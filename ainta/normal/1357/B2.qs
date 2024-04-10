namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (Inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        body (...) {
            let len = Length(Inputs);
            using ((c0,c1,c2,c3,qs) = (Qubit(),Qubit(),Qubit(),Qubit(), Qubit[len])) {
                X(c0);
                X(c1);
                X(c2);
                X(c3);
                for (i in 0..len - 1){
                    CNOT(Inputs[i],qs[i]);
                }
                for (i in 0..2..len - 1){
                    CCNOT(qs[i], c1, c0);
                    CCNOT(qs[i], c0, c1);
                }
                for (i in 1..2..len - 1){
                    CCNOT(qs[i], c3, c2);
                    CCNOT(qs[i], c2, c3);
                }
                (ControlledOnInt(15,X))([c0,c1,c2,c3],output);
                (ControlledOnInt(5,X))([c0,c1,c2,c3],output);
                (ControlledOnInt(10,X))([c0,c1,c2,c3],output);
                for (i in 1..2..len - 1){
                    CCNOT(qs[i], c2, c3);
                    CCNOT(qs[i], c3, c2);
                }
                for (i in 0..2..len - 1){
                    CCNOT(qs[i], c0, c1);
                    CCNOT(qs[i], c1, c0);
                }

                for (i in 0..len - 1){
                    CNOT(Inputs[i],qs[i]);
                }
                X(c0);
                X(c1);
                X(c2);
                X(c3);
            }
 
        }
 
        adjoint auto;
    }
}