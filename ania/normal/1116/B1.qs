namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation Solve (x : Qubit[]) : Int {
        body (...) {
            let pi = PI();
            let theta = pi * 2.0 / 3.0;
            let Omega = R1(theta, _);
            SWAP(x[0], x[2]);
            (ControlledOnInt(0, Omega))(x[0..1], x[2]);
            (ControlledOnInt(0, Omega))([x[0], x[2]], x[1]);
            (ControlledOnInt(0, Omega))([x[0], x[2]], x[1]);
            (ControlledOnInt(0, X))(x[0..1], x[2]);
            Z(x[1]);
            (ControlledOnInt(0, H))([x[0]], x[1]);
            (ControlledOnInt(0, X))([x[0]], x[1]);
            //DumpMachine("");
            Ry(-2.0 * ArcCos(Sqrt(2.0) / Sqrt(3.0)), x[0]);
            //DumpMachine("");
            let m1 = M(x[0]);
            let m2 = M(x[1]);
            let m3 = M(x[2]);
            if (m1 == Zero && m2 == Zero && m3 == Zero) {
                return 1;
            }
            return 0;
        }
    }
}