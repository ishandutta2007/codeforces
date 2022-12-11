namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
            mutable res = 0;
            for (i in 0..n-1) {
                if (bits0[i] != bits1[i]) {
                    mutable cur_bit = false;
                    if (M(qs[i]) == One) { set cur_bit = true; }
                    if (cur_bit == bits1[i]) { set res = 1; }
                }
            }
            return res;
        }
    }

    operation Go (n : Int, b0 : Int, b1 : Int, ch : Int) : Bool {
        body {
            mutable bi0 = new Bool[n];
            mutable bi1 = new Bool[n];
            mutable bb0 = b0;
            mutable bb1 = b1;
            mutable res = false;
            using (qi = Qubit[n]) {
                for (i in 0..n-1) {
                    set bi0[i] = bb0%2 == 1;
                    set bi1[i] = bb1%2 == 1;
                    set bb0 = bb0/2;
                    set bb1 = bb1/2;
                    if (ch==0) {
                        if (bi0[i]) {
                            X(qi[i]);
                        }
                    } else {
                        if (bi1[i]) {
                            X(qi[i]);
                        }
                    }
                }
                let ret = Solve(qi, bi0, bi1);
                if (ch == ret) { set res = true; }
                ResetAll(qi);
            }
            return res;
        }
    }
}