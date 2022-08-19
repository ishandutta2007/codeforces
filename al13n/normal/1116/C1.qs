namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function alter(n : Int, v : Int) : Bool[] {
        mutable bits = new Bool[n];
        for (i in 0..n-1) {
            set bits w/= i <- i%2==v;
        }
        return bits;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit is Adj {
        (ControlledOnBitString(alter(Length(x), 0), X))(x, y);
        (ControlledOnBitString(alter(Length(x), 1), X))(x, y);
    }

//    @EntryPoint()
//    operation test() : Unit {
//        mutable cnt = 0;
//        for (i in 1..100) {
//            using (q = Qubit()) {
//                H(q);
//                R1(0./3.*PI(), q);
//                let r = Solve(q);
//                if (r == 0) {
//                    set cnt += 1;
//                }
//                //Message($"{r}");
//                Reset(q);
//            }
//        }
//        Message($"{cnt}");
//    }
}