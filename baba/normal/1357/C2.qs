namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        mutable res_parity = Zero;
        if(parity == 1) {
            set res_parity = One;
        }
        using(ac = Qubit()) {
            repeat {
                ResetAll(qs);
                Reset(ac);
                for(i in 0..n-1){
                    H(qs[i]);
                }
                for(i in 0..n-1){
                    CNOT(qs[i], ac);
                }
                let res = M(ac);
            }
            until (res == res_parity);
            Reset(ac);
        }
    }
}