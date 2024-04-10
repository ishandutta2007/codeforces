namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;

    operation doit (qs : Qubit[]) : Unit is Adj {
        Ry(2.*ArcSin(1./Sqrt(3.)), qs[0]);
        (ControlledOnInt(0, H))([qs[0]], qs[1]);
        (ControlledOnInt(0, X))([qs[0], qs[1]], qs[2]);
        //DumpRegister((), qs);
        R1(2./3.*PI(), qs[1]);
        R1(4./3.*PI(), qs[2]);
    }

    operation Solve (qs : Qubit[]) : Int {
        Adjoint doit(qs);
        let r = MultiM(qs);
        if (r[0] == Zero and r[1] == Zero and r[2] == Zero) {
            return 0;
        } else {
            return 1;
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        mutable cnt = 0;
//        for (i in 1..1) {
//            using (qs = Qubit[3]) {
//                doit(qs);
//                R1(2./3.*PI(), qs[1]);
//                R1(4./3.*PI(), qs[2]);
//                DumpRegister((), qs);
//                let r = Solve(qs);
//                set cnt += r;
//                //Message($"{r}");
//                ResetAll(qs);
//            }
//        }
//        Message($"{cnt}");
//    }
}