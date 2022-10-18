namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        using(ac = Qubit()) {
            repeat {
                ResetAll(qs);
                Reset(ac);
                for(i in 0..n-1){
                    H(qs[i]);
                }
                Controlled X(qs, ac);
                let res = M(ac);
            }
            until (res == Zero);
            Reset(ac);
        }
    }
}