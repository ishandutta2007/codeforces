namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (qs : Qubit[]) : Unit {
        for (q in qs) {
            H(q);
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        DumpUnitaryToFiles(4, Solve);
//    }
}