namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function FirstTrue(a : Bool[]) : Int {
        mutable r = -1;
        for (i in 0..Length(a)-1) {
            if (a[i] and r == -1) {
                set r = i;
            }
        }
        return r;
    }

    operation Solve (qs : Qubit[], bits : Bool[]) : Unit {
        let i0 = FirstTrue(bits);
        H(qs[i0]);
        for (i in i0+1..Length(bits)-1) {
            if (bits[i]) {
                CNOT(qs[i0], qs[i]);
            }
        }
    }

//    @EntryPoint()
//    operation test() : Unit {
//        DumpUnitaryToFiles(4, Solve);
//    }
}