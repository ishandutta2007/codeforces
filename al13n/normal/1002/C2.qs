namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (q : Qubit) : Int {
        if (Random([.5, .5]) == 1) {
            H(q);
            if (M(q) == One) {
                return 0;
            } else {
                return -1;
            }
        } else {
            if (M(q) == One) {
                return 1;
            } else {
                return -1;
            }
        }
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