namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable res = 0;
            mutable zeros = 0;
            mutable ones = 0;
            let n = Length(qs);
            for (i in 0..n-1) {
                if (M(qs[i]) == One) {
                    set ones = ones+1;
                } else {
                    set zeros = zeros+1;
                }
            }
            if (ones > 0) {
                if (zeros > 0) {
                    set res = 1;
                }
            }
            return res;
        }
    }

}