namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q : Qubit) : Int {
        body {
            H(q);
            mutable res = 1;
            if (M(q) == One) { set res = -1; }
            return res;
        }
    }
}