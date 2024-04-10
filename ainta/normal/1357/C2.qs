namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (ancilla = Qubit()) {
            repeat {
                ResetAll(qs);
                Reset(ancilla);
                ApplyToEach(H, qs);
                for(i in 0..Length(qs)-1){
                    Controlled X(qs[i..i], ancilla);
                }
                mutable res = M(ancilla);
                Reset(ancilla);
            } until ((res == Zero) == (parity == 0))
            fixup {
                ResetAll(qs);
            }
        }
    }
}