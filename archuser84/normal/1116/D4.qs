namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (qs : Qubit[]) : Unit is Adj+Ctl {
        let N = Length(qs);

        ApplyToEachCA(CNOT(qs[N-1], _), qs[0..N-2]);
        H(qs[N-1]);
        ApplyToEachCA(CNOT(qs[N-1], _), qs[0..N-2]);

        ApplyToEachCA(CNOT(qs[N-1], _), qs[0..N-2]);
        ApplyToEachCA(X, qs[0..N-2]);
        let k = LittleEndian(qs[0..N-2]);
        IncrementByModularInteger((1 <<< (N-1))-1, 1 <<< (N-1), k);
        ApplyToEachCA(CNOT(qs[N-1], _), qs[0..N-2]);
    }
}