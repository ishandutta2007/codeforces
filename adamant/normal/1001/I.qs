namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        using ((qs, q) = (Qubit[N], Qubit())) {
            X(q);
            H(q);
            ApplyToEach(H, qs);
            Uf(qs, q);
            ApplyToEach(H, qs);
            let res = (ResultArrayAsInt(MultiM(qs)) == 0);
            ResetAll(qs);
            Reset(q);
            return res;
        }
    }
}