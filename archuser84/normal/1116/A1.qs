namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(2.0*ArcCos(1.0/Sqrt(3.0)), qs[0]);
        Controlled H([qs[0]],qs[1]);
        CNOT(qs[1],qs[0]);
    }
}