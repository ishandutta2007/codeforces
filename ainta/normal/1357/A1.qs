namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;

    operation PrepareUniform(inputQubits : Qubit[]) : Unit is Adj + Ctl {
        ApplyToEachCA(H, inputQubits);
    }
    
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable numOnes = 0;
        using (qubits = Qubit[2]) {
            Set(Zero, qubits[0]);
            Set(One, qubits[1]);
            unitary(qubits);
            if(M(qubits[0]) == One){
                set numOnes += 1;
            }
            Set(Zero, qubits[0]);
            Set(Zero, qubits[1]);
        }
        if(numOnes != 0){
            return 1;
        }
        return 0;
    }
}