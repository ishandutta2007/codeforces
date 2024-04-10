namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = Zero;
        using(q = Qubit()) {
            U(q);
            H(q);
            U(q);
            H(q);
            set ans = M(q);
            Reset(q);
		}
        if(ans == One){return 1;}
        else{return 0;}
    }
}