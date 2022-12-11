namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
            mutable j = -1;
            mutable k = -1;
            for (i in 0..n-1) {
                mutable sum = 0;
                if (bits0[i]) {
                    set sum = sum+1;
                }
                if (bits1[i]) {
                    set sum = sum+2;
                }
                if (sum==3) {
                    X(qs[i]);
                } else {
                    if (sum>0) {
                        if (j == -1) {
                            H(qs[i]);
                            set j = i;
                            set k = sum;
                        } else {
                            CNOT(qs[j], qs[i]);
                            if (sum != k) {
                                X(qs[i]);
                            }
                        }
                    }
                }
            }
        }
    }

    operation Go (n : Int, b0 : Int, b1 : Int) : Bool {
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
                }
                Solve(qi, bi0, bi1);
                DumpMachine("");
                ResetAll(qi);
            }
            return res;
        }
    }

}