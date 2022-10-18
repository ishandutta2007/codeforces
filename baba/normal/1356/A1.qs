namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    using (qubit = Qubit()) {
        unitary(qubit);
        let result = M(qubit);
        Reset(qubit);
        if(result == One){
            return 1;
        }
        else {
            return 0;
        }
    }
    }
}