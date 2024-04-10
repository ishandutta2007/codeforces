namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation IsPeriodic (x : Qubit[], y : Qubit, p : Int) : Unit {
        body (...) {
            let n = Length(x);
            for (i in 0..(n-1-p)) {
                CNOT(x[i + p], x[i]);
                X(x[i]);
            }
            (Controlled X)(x[0..(n-1-p)], y);
            for (i in 0..(n-1-p)) {
                X(x[i]);
                CNOT(x[i + p], x[i]);
            }
        }
        adjoint auto;
    }


    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            let m = n / 2;
            using (qs = Qubit[m]) {
                for (p in n-m..n-1) {
                    IsPeriodic(x, qs[p - (n - m)], p);
                }
                ApplyToEachA(X, qs);
                (Controlled X)(qs, y);
                ApplyToEachA(X, qs);
                X(y);
                for (p in n-m..n-1) {
                    IsPeriodic(x, qs[p - (n - m)], p);
                }
            }
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