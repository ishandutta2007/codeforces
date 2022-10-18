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
        using (qs = Qubit[2]) {
            H(qs[0]);H(qs[1]);
            CZ(qs[0], qs[1]);
            X(qs[0]);
            Controlled unitary([qs[0]], qs[1]);
            Controlled Z([qs[0]], qs[1]);
            Controlled unitary([qs[0]], qs[1]);
            H(qs[0]);
            let m = M(qs[0]);
            if(m == Zero) {
                // +- XZ
                ResetAll(qs);
                H(qs[0]);H(qs[1]);
                CZ(qs[0], qs[1]);
                X(qs[0]);
                Controlled unitary([qs[0]], qs[1]);
                H(qs[0]);
                let m2 = M(qs[0]);
                ResetAll(qs);
                if(m2 == Zero) {
                    return 1;
                }
                else {
                    return 3;
                }
            }
            else {
                // +- Y
                ResetAll(qs);
                H(qs[0]);
                Controlled Y([qs[0]], qs[1]);
                Controlled unitary([qs[0]], qs[1]);
                H(qs[0]);
                let m2 = M(qs[0]);
                ResetAll(qs);
                if(m2 == Zero) {
                    return 0;
                }
                else {
                    return 2;
                }
            }
        }
    }
}