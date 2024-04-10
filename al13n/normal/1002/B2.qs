namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Int {
        let r = MeasureInteger(LittleEndian(qs));
        if (r == 0 or (r &&& (r-1)) != 0) {
            return 0;
        } else {
            return 1;
        }
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    using (qs = Qubit[1]) {
    //        Solve(qs);
    //        DumpRegister((), qs);
    //        ResetAll(qs);
    //    }
    //}
}