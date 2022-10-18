namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            let res = M(qs[0]);
            ResetAll(qs);
            if(res == One) {
                // Either CNOT21 OR SWAP
                X(qs[0]);
                unitary(qs);
                let res2 = M(qs[1]);
                ResetAll(qs);
                if(res2 == One) {
                    // SWAP
                    return 3;
                }
                else {
                    // CNOT21
                    return 2;
                }
            }
            else {
                // Either CNOT12 OR I*I
                X(qs[0]);
                unitary(qs);
                let res2 = M(qs[1]);
                ResetAll(qs);
                if(res2 == One) {
                    // CNOT12
                    return 1;
                }
                else {
                    // I * I
                    return 0;
                }
            }
        }
    }
}