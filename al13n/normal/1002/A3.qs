namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function FirstDiff(a : Bool[], b : Bool[]) : Int {
        for (i in 0..Length(a)-1) {
            if (a[i] != b[i]) {
                return i;
            }
        }
        return -1;
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        let i0 = FirstDiff(bits0, bits1);
        H(qs[i0]);
        for (i in 0..Length(qs)-1) {
            if (bits0[i] and bits1[i]) {
                X(qs[i]);
            }
            if (i>i0 and bits0[i]!=bits1[i]) {
                CNOT(qs[i0], qs[i]);
                if (bits0[i]!=bits0[i0]) {
                    X(qs[i]);
                }
            }
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        DumpUnitaryToFiles(4, Solve);
//    }
}