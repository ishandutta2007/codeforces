namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
 
    operation Solve(unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable s = 0;
        mutable r = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            CNOT(q1,q2);
            unitary(q1);
            CNOT(q2,q1);
            H(q2);
            let r1 = M(q1);
            let r2 = M(q2);
            Reset(q1);
            Reset(q2);
            set s = s + (r1 == One ? 1 | 0);
            set s = s + (r2 == One ? 2 | 0);
            if(s == 0){
                set r = 0;
            }
            if(s == 1){
                set r = 1;
            }
            if(s == 2){
                set r = 3;
            }
            if(s == 3){
                set r = 2;
            }
            return r;
        }
    }
}