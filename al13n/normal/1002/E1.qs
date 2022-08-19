namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        mutable ans = new Int[N];
        using ((qs, y) = (Qubit[N], Qubit())) {
            X(y);
            H(y);
            for (q in qs) {
                H(q);
            }
            Uf(qs, y);
            for (q in qs) {
                H(q);
            }
            let r = MultiM(qs);
            for (i in 0..N-1) {
                if (r[i] == One) {
                    set ans w/= i <- 1;
                }
            }
            ResetAll(qs);
            Reset(y);
        }
        return ans;
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