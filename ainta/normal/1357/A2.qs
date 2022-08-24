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
        mutable r1 = new Result[0];
        mutable r2 = new Result[0];
        using (qubits = Qubit[4]) {
            Set(Zero, qubits[0]);
            Set(One, qubits[1]);
            Set(One, qubits[2]);
            Set(Zero, qubits[3]);
            unitary(qubits[0..1]);
            unitary(qubits[2..3]);
            set r1 += [M(qubits[0])];
            set r1 += [M(qubits[1])];
            set r2 += [M(qubits[2])];
            set r2 += [M(qubits[3])];
            Set(Zero, qubits[0]);
            Set(Zero, qubits[1]);
            Set(Zero, qubits[2]);
            Set(Zero, qubits[3]);
        }
        let s1 = ResultArrayAsInt(r1);
        let s2 = ResultArrayAsInt(r2);
        if(s1 == 2 and s2 == 1){
            return 0;
        }
        if(s1 == 1 and s2 == 2){
            return 3;
        }
        if(s1 == 3){
            return 2;
        }
        return 1;
    }
}