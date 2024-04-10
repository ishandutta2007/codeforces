namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        for (i in 0..Length(bits0)-1){
            if(bits0[i] != bits1[i]) {
                return ResultAsBool(M(qs[i])) == bits0[i] ? 0 | 1;
            }
        }
        return -1;
    }
}