namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
    using (qubits = Qubit[2]) {
        unitary(qubits);
        let result = M(qubits[1]);
        ResetAll(qubits);
        if(result == One){
            return 0;
        }
        else {
            return 1;
        }
    }
    }
}