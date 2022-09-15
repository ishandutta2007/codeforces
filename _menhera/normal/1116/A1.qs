namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        
        using(q = Qubit())
        {
          repeat {
            ResetAll(qs);
            Reset(q);
            H(qs[0]);
            H(qs[1]);
            CCNOT(qs[0], qs[1], q);
            let r = M(q);
          } until (r == Zero)
          fixup {}
        }
    }
}