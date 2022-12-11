namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let x0 = M(qs[0]);
            let x1 = M(qs[1]);
            mutable res = 0;
            if (x0 == One) { set res = res + 1; }
            if (x1 == One) { set res = res + 2; }
            return res;
        }
    }

    operation MakeBell (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if (index % 2 == 1) {
                X(qs[0]);
            }
            if (index > 1) {
                X(qs[1]);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }

    operation Go (index : Int, measure : Int) : Bool {
        body {
            mutable res = false;
            using (qi = Qubit[2]) {
                MakeBell(qi, index);
                let ret = Solve(qi);
                if (index == ret) { set res = true; }
                ResetAll(qi);
            }
            return res;
        }
    }
}