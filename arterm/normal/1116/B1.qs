namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;


    operation Solve (qs : Qubit[]) : Int {
        let alpha = 2. * PI() / 3.;
        Rz(2. * alpha, qs[1]);
        Rz(alpha, qs[2]);
        X(qs[0]);
        CCNOT(qs[0], qs[1], qs[2]);
        (Controlled H)([qs[0]], qs[1]);
        CNOT(qs[0], qs[2]);
        
        let gamma = ArcSin(Sqrt(2. / 3.));
        Ry(-2. * gamma, qs[0]);

        DumpMachine("dump.txt");

        mutable all_zero = true;
        for (i in 0..2) {
            if (M(qs[i]) == One) {
                set all_zero = false;
            }
        }

        return all_zero ? 0 | 1;
    }

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

    operation GetState(qs : Qubit[], n : Int) : Unit {
        WState_Arbitrary_Reference(qs);
        let alpha = 2. * PI() / 3.;
        if (n == 0) {
            Rz(alpha, qs[1]);
            Rz(2. * alpha, qs[2]);
        } else {
            Rz(2. * alpha, qs[1]);
            Rz(alpha, qs[2]);
        }
    }


    operation Test (n : Int) : Int {
        mutable res = 0;
        using (register = Qubit[3]) {
            let x = register[0..2];
            GetState(x, n);
            set res = Solve(x);
            ResetAll(register);
        }
        return res;
    }

}