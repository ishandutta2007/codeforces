namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation WState_Arbitrary_Reference (qs : Qubit[]) : Unit {
        
        body (...) {
            let N = Length(qs);
            
            if (N == 1) {
                // base case of recursion: |1
                X(qs[0]);
            } else {
                // |W_N = |0|W_(N-1) + |1|0...0
                // do a rotation on the first qubit to split it into |0 and |1 with proper weights
                // |0 -> sqrt((N-1)/N) |0 + 1/sqrt(N) |1
                let theta = ArcSin(1.0 / Sqrt(ToDouble(N)));
                Ry(2.0 * theta, qs[0]);
                
                // do a zero-controlled W-state generation for qubits 1..N-1
                X(qs[0]);
                Controlled WState_Arbitrary_Reference(qs[0 .. 0], qs[1 .. N - 1]);
                X(qs[0]);
            }
        }
        
        adjoint invert;
        controlled distribute;
        controlled adjoint distribute;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let theta = ArcSin(Sqrt(1. / 3.));
        Ry(2.0 * theta, qs[0]);
        X(qs[0]);
        (Controlled H)([qs[0]], qs[1]);
        X(qs[0]);
    }


    operation Test (n : Int) : Int[] {
        mutable measurment = new Int[n];
        using (register = Qubit[n]) {
            let x = register[0..(n-1)];
            Solve(x);
            DumpMachine("dump.txt");
            for (i in 0..n-1) {
                if (M(register[i]) == One) {
                    set measurment[i] = 1;
                }
            }
            ResetAll(register);
        }
        return measurment;
    }

}