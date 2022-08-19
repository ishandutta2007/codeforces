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
        Controlled Z([qs[0]], qs[1]);
        H(qs[0]);
        H(qs[1]);
        // --, +-, -+, ++
        return 3 - MeasureInteger(LittleEndian(qs));
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