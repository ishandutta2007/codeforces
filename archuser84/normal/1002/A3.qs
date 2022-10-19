namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[], b0 : Bool[], b1 : Bool[]) : Unit {
        let n = Length(qs);
        mutable f = -1;
        for(i in 0..n-1) {
            if(b0[i] != b1[i] and f == -1){set f = i;}
            if(b0[i] and b1[i]) {X(qs[i]);}
		}
        H(qs[f]);
        for(i in f+1..n-1) {
            if(b0[i] != b1[i]) {
                CNOT(qs[f], qs[i]);
                if(b0[f] != b0[i]){ X(qs[i]);}
			}  
		}
    }
}