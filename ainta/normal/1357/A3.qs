namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (q = Qubit()) {
            unitary(q);
            X(q);
            unitary(q);
            let tp = M(q);
            Reset(q);
            if(tp == Zero){
                set res = 0;
            }
            else{
                set res = 1;
            }
        }
        return res;
    }
}