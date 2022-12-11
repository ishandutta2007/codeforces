namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            H(qs[0]);
            for (i in 1 .. n-1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }

    operation Go (n : Int, measure : Int) : Bool[] {
        body {
            mutable res = new Bool[n];
            for (i in 0 .. n-1) {
                set res[i] = false;
            }
            using (qi = Qubit[n]) {
                Solve(qi);
                if (M(qi[measure]) == One) { set res[measure] = true; }
                for (i in 0 .. n-1) {
                    if (M(qi[i]) == One) { set res[i] = true; }
                }
                ResetAll(qi);
            }
            return res;
        }
    }
}