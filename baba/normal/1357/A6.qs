namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using (qs = Qubit[2]) {
            H(qs[0]);CNOT(qs[0], qs[1]);
            unitary(qs[1]);
            CNOT(qs[0], qs[1]);H(qs[0]);
            let m0 = M(qs[0]);
            let m1 = M(qs[1]);
            ResetAll(qs);
            if(m0 == Zero and m1 == Zero){
                set ret = 0;
            }
            if(m0 == Zero and m1 == One){
                set ret = 1;
            }
            if(m0 == One and m1 == Zero){
                set ret = 3;
            }
            if(m0 == One and m1 == One){
                set ret = 2;
            }
        }
        return ret;
    }
}