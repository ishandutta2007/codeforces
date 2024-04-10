namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(2.*ArcSin(1./Sqrt(3.)), qs[0]);
        Controlled H([qs[0]], qs[1]);
        H(qs[1]);
    }

//    @EntryPoint()
//    operation test() : Unit {
//        using (qs = Qubit[2]) {
//            Solve(qs);
//            DumpRegister((), qs);
//            ResetAll(qs);
//        }
//        //Message($"{i} {x}");
//    }
}