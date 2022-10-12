namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;


    operation Solve (qs : Qubit[]) : Unit {
        using (test = Qubit()) {
            repeat {
                for (q in qs) {
                    H(q);
                }

                Controlled X(qs, test);
                let res = M(test);
            }
            until (res == Zero)
            fixup {
                X(test);
                for (q in qs) {
                    X(q);
                }
            }
        }
    }
    
    //@EntryPoint()
    operation RunQsharp () : Unit {
        using (register = Qubit[3]) {
            Solve(register);
            DumpRegister((), register);
            for (q in register) {
                Reset(q);
            }
        }
    }
}