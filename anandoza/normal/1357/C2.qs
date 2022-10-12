namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;


    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (test = Qubit()) {
            repeat {
                for (q in qs) {
                    H(q);
                }

                for (q in qs) {
                    Controlled X([q], test);
                }
                let res = M(test);
            }
            until (res == One and parity == 1 or res == Zero and parity == 0)
            fixup {
                if (parity == 0) {
                    X(test);
                }
                for (q in qs) {
                    Reset(q);
                }
            }
            if (parity == 1) {
                X(test);
            }
        }
    }
    
    //@EntryPoint()
    operation RunQsharp () : Unit {
        using (register = Qubit[3]) {
            Solve(register, 1);
            DumpRegister((), register);
            for (q in register) {
                Reset(q);
            }
        }
    }
}