namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);H(qs[1]);
            Controlled unitary([qs[0]], (2.0 * PI(), qs[1]));
            H(qs[0]);H(qs[1]);
            let res = M(qs[0]);
            ResetAll(qs);
            if(res == Zero) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}