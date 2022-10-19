namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Shift (qs : Qubit[]) : Unit {
        body (...) {
            SWAP(qs[0], qs[1]);
            SWAP(qs[0], qs[2]);
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }

    operation Calc (qs : Qubit[], x : Qubit[]) : Unit {
        body (...) {
            X(qs[0]);
            for (q in x) {
                (Controlled Shift)([q], qs);
            }
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using (qs = Qubit[3]) {
                Calc(qs, x);
                CNOT(qs[0], y);
                (Adjoint Calc)(qs, x);
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