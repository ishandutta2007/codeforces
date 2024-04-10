namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (qs : Qubit[]) : Unit {
        using (a = Qubit()) {
            repeat {
                H(qs[0]);
                H(qs[1]);
                Controlled X(qs, a);
                X(qs[0]);
                X(qs[1]);
            } until (M(a) == Zero)
            fixup {
                X(a);
            }
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        using (A = Qubit[2]) {
//            Solve(A);
//            DumpRegister((), A);
//            //Message($"{r}");
//            ResetAll(A);
//        }
//    }
}