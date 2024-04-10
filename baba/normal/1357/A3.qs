namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[1]) {
            unitary(qs[0]);
            Z(qs[0]);
            unitary(qs[0]);
            let res = M(qs[0]);
            ResetAll(qs);
            if(res == One){
                return 0;
            }
            else {
                return 1;
            }
        }
    }
}