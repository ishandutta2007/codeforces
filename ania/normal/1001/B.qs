namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], index : Int) : ()
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

    operation Go (index : Int, measure : Int) : Bool[] {
        body {
            mutable res = new Bool[2];
            set res[0] = false;
            set res[1] = false;
            using (qi = Qubit[2]) {
                Solve(qi, index);
                if (M(qi[measure]) == One) { set res[measure] = true; }
                if (M(qi[1-measure]) == One) { set res[1-measure] = true; }
                ResetAll(qi);
            }
            return res;
        }
    }
}