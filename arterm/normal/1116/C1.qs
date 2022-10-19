namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Prep (x : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            for (i in 0..2..n-1) {
                X(x[i]);
            }
            X(x[0]);
            ApplyToEachA(CNOT(x[0], _), x[1..n-1]);
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            Prep(x);
            (Controlled X)(x[1..n-1], y);
            (Adjoint Prep)(x);
        }
        adjoint auto;
    }

    operation Test (n : Int, imask : Int) : Int[] {
        mutable measurment = new Int[n + 1];
        mutable mask = imask;
        using (register = Qubit[n + 1]) {
            let x = register[0..(n-1)];
            let y = register[n];
            for (i in 0..(n-1)) {
                if (mask % 2 == 1) {
                    X(x[i]);
                }
                set mask = mask / 2;
            }
            Solve(x, y);
            for (i in 0..n) {
                if (M(register[i]) == One) {
                    set measurment[i] = 1;
                }
            }
            ResetAll(register);
        }
        return measurment;
    }

}