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


    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (qs = Qubit[3]) {
            for (q in inputs) {
                Controlled X([q, qs[0], qs[1]], qs[2]);
                CCNOT(q, qs[0], qs[1]);
                CNOT(q, qs[0]);
            }
            (ControlledOnInt(Length(inputs)/2, X))(qs, output);
            for (q in inputs) {
                CNOT(q, qs[0]);
                CCNOT(q, qs[0], qs[1]);
                Controlled X([q, qs[0], qs[1]], qs[2]);
            }
        }
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    using ((qs, a) = (Qubit[10], Qubit())) {
    //        X(qs[1]);
    //        X(qs[3]);
    //        X(qs[4]);
    //        X(qs[7]);
    //        X(qs[9]);
    //        X(qs[8]);
    //        Solve(qs, a);
    //        Message($"{M(a)}");
    //        ResetAll(qs + [a]);
    //    }
    //}
}