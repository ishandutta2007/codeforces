namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for(i in 0..N-2){H(qs[i]);}
        Controlled H(qs[0..N-2], qs[N-1]);
        if(M(qs[N-1])==One){for(i in 0..N-1){X(qs[i]);} Solve(qs);}
        else{Controlled H(qs[0..N-2], qs[N-1]); H(qs[N-1]);}
    }
}