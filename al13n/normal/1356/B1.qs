namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (A : LittleEndian) : Unit is Adj+Ctl {
        using (C = Qubit[Length(A!)]) {
            X(C[0]);
            for (i in 0..Length(A!)-2) {
                Controlled X([C[i], A![i]], C[i+1]);
            }
            //DumpRegister((), C);
            for (i in Length(A!)-1..-1..1) {
                CNOT(C[i], A![i]);
                Controlled X([C[i-1], A![i-1]], C[i]);
            }
            X(A![0]);
            X(C[0]);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        using (A = Qubit[5]) {
//            X(A[0]);
//            X(A[1]);
//            Solve(LittleEndian(A));
//            mutable r = new Result[Length(A)];
//            for (i in 0..Length(A)-1) {
//                set r w/= i <- M(A[i]);
//            }
//            Message($"{r}");
//            ResetAll(A);
//        }
//    }
}