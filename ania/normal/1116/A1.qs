namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Math;
    
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
            X(qs[0]);
            Ry(-2.0 * ArcCos(1.0 / Sqrt(3.0)), qs[0]);
            (ControlledOnInt(0, H))([qs[0]], qs[1]);
        }
        adjoint auto;
    }
}