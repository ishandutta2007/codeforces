namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function ToInt(r : Result) : Int {
        if (r == One) {
            return 1;
        } else {
            return 0;
        }
    }
    function BoolToInt(r : Bool) : Int {
        if (r) {
            return 1;
        } else {
            return 0;
        }
    }


    operation Solve (qs : Qubit[]) : Unit {
        using ((a) = (Qubit())) {
            repeat {
                for (q in qs) {
                    H(q);
                }
                Controlled X(qs, a);
            } until (M(a) == Zero)
            fixup {
                for (q in qs + [a]) {
                    X(q);
                }
            }
        }
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    using (qs = Qubit[1]) {
    //        Solve(qs);
    //        DumpMachine(());
    //        ResetAll(qs);
    //    }
    //}
}