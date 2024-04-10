namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        body {
            mutable measurment = 0;
            let n = Length(qs);
            for (i in 0..(n - 1)) {
                if ((M(qs[i]) == One) != bits0[i]) {
                    set measurment = 1;
                }
            }
            return measurment;
        }
    }
}