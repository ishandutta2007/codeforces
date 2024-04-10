
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    using (qubits = Qubit[2]) {
        H(qubits[0]);
        CNOT(qubits[0], qubits[1]);
        Controlled unitary([qubits[0]], qubits[1]);
        CNOT(qubits[0], qubits[1]);
        H(qubits[0]);
        let result = M(qubits[0]);
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