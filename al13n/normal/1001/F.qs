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



    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        for (i in 0..Length(qs)-1) {
            if (bits0[i] != bits1[i]) {
                if ((M(qs[i]) == One) == bits0[i]) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
        return -1;
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    mutable c = 0;
    //    for (i in 1..100) {
    //        using (q = Qubit()) {
    //            H(q);
    //            set c += Solve(q);
    //            Reset(q);
    //        }
    //    }
    //    Message($"{c}");
    //}
}