namespace Solution {
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(2.0 * ArcCos(Sqrt(2.0/3.0)), qs[0]);
        X(qs[0]);
        Controlled H ([qs[0]], qs[1]);
        X(qs[0]);
    }
}