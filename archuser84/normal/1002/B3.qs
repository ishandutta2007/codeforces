namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Int {
        H(qs[0]); H(qs[1]);
        return ResultArrayAsInt([M(qs[1]),M(qs[0])]);
    }
}