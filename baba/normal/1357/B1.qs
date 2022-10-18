namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation Increment(qs : Qubit[]) : Unit is Adj+Ctl{
        let n = Length(qs);
        for(i in n-1..-1..1){
            Controlled X(qs[0..i-1],qs[i]);
        }
        X(qs[0]);
    }

    operation Decrement(qs : Qubit[]) : Unit is Adj+Ctl {
        X(qs[0]);
        for (i in 0 .. Length(qs) - 2) {
            Controlled X(qs[0..i], qs[i+1]);
        }
    }

    operation Solve (qs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(qs);
        let ac_len = 3;
        using(ac = Qubit[ac_len]) {
            for(i in 0..n-1){
                Controlled Increment([qs[i]], ac);
            }
            ApplyXorInPlace(n / 2, LittleEndian(ac));
            for(i in 0..ac_len - 1){
                X(ac[i]);
            }
            Controlled X (ac, output);
            for(i in 0..ac_len - 1){
                X(ac[i]);
            }
            ApplyXorInPlace(n / 2, LittleEndian(ac));
            for(i in 0..n-1){
                Controlled Decrement([qs[i]], ac);
            }
        }
    }
}