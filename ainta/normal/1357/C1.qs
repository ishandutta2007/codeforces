namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[]) : Unit {
        using (ancilla = Qubit()) {
            repeat {
                ResetAll(qs);
                Reset(ancilla);
                ApplyToEach(H, qs);
                Controlled X(qs, ancilla);
            } until (M(ancilla) == Zero)
            fixup {
                ResetAll(qs);
            }
        }
    }
}