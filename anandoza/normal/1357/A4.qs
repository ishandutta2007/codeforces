namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;


    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]);

            Controlled unitary(q[0..0], (2.0 * PI(), q[1]));

            Adjoint H(q[0]);

            return MResetZ(q[0]) == One ? 0 | 1;
        }
    }

    
    operation F0(theta: Double, x : Qubit) : Unit is Adj+Ctl {
        Rz(theta, x);
    }
    operation F1(theta: Double, x : Qubit) : Unit is Adj+Ctl {
        R1(theta, x);
    }

    //@EntryPoint()
    operation RunQsharp () : Unit {
        Message("F0: " + IntAsString(Solve(F0)));
        Message("F1: " + IntAsString(Solve(F1)));
    }
}