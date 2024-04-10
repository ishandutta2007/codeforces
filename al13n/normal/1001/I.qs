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



    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        using (x = Qubit[N+1]) {
            X(x[N]);
            for (q in x) {
                H(q);
            }
            Uf(x[...N-1], x[N]);
            for (q in x) {
                H(q);
            }
            let r = MeasureInteger(LittleEndian(x[...N-1])) == 0;
            ResetAll(x);
            return r;
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