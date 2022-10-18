namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;
 
   operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[1]) {
            mutable is_ry = false;
            for (i in 1 .. 10){
                for(j in 1 .. 100) {
                    if(IntAsDouble(j) * theta < PI()) {
                        unitary(qs[0]);
                    }
                }
                let res = M(qs[0]);
                ResetAll(qs);
                if(res == One) {
                    set is_ry = true;
                }
            }
            if(is_ry == true){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}