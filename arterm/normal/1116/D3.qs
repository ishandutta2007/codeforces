namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    open Microsoft.Quantum.Extensions.Diagnostics;


    operation Solve (x : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            ApplyToEach(CNOT(x[0], _), x[1..n-1]);
            H(x[0]);
            ApplyToEach(CNOT(x[0], _), x[1..n-1]);
        }
    }

    operation Test (n : Int, imask : Int) : (Int[], Int[]) {
        mutable before = new Int[n];
        mutable after = new Int[n];
        mutable mask = imask;

        using (register = Qubit[n]) {
            let x = register;
            
            for (i in 0..(n-1)) {
                if (mask % 2 == 1) {
                    X(x[i]);
                    set before[i] = 1;
                }
                set mask = mask / 2;
            }
            Solve(x);
            for (i in 0..(n-1)) {
                if (M(register[i]) == One) {
                    set after[i] = 1;
                }
            }
            ResetAll(register);
        }
        return (before, after);
    }

     operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");
                
                ResetAll(qs);
            }
        }
    }

    // The operation which is called from C# code
    operation CallDumpUnitary (N : Int) : Unit {
        // make sure the operation passed to DumpUnitaryToFiles matches the number of qubits set in Driver.cs
        let unitary = Solve;

        DumpUnitaryToFiles(N, unitary);
    }

}