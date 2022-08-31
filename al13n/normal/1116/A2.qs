namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            H(b);
            for (i in 0..3) {
                for (j in 0..Length(bits[i])-1) {
                    if (bits[i][j]) {
                        (ControlledOnInt(i, X))([a, b], qs[j]);
                    }
                }
            }
            (ControlledOnBitString(bits[1], X))(qs, a);
            (ControlledOnBitString(bits[2], X))(qs, b);
            (ControlledOnBitString(bits[3], X))(qs, a);
            (ControlledOnBitString(bits[3], X))(qs, b);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        using (qs = Qubit[3]) {
//            Solve(qs, [[false, true, false], [false, false, false], [true, true, true], [true, false, true]]);
//            DumpRegister((), qs);
//            ResetAll(qs);
//        }
//        //Message($"{i} {x}");
//    }
}