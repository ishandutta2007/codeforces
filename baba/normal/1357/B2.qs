namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Math;

    operation IncrementMod3(qs : Qubit[]) : Unit is Adj+Ctl{
        CNOT(qs[0], qs[1]);
        X(qs[0]);
        using (ac = Qubit()){
            Controlled X(qs, ac);
            CNOT(ac, qs[0]);
            CNOT(ac, qs[1]);
            (ControlledOnInt(0, X))(qs, ac);
        }
    }

    operation Solve (qs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(qs);
        let ac_len = 2;
        using(ac = Qubit[ac_len]) {
            for(i in 0..n-1){
                for (j in 1..PowI(2, i) % 3){
                    Controlled IncrementMod3([qs[i]], ac);
                }
            }
            for(i in 0..ac_len - 1){
                X(ac[i]);
            }
            Controlled X (ac, output);
            for(i in 0..ac_len - 1){
                X(ac[i]);
            }
            for(i in 0..n-1){
                for (j in 1..PowI(2, i) % 3){
                    Controlled Adjoint IncrementMod3([qs[i]], ac);
                }
            }
        }
    }
}