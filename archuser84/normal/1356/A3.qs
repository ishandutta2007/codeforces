namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (u : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = false;
        using(q = Qubit()) {
            H(q);
            u(q);
            u(q);
            H(q);
            set ans = ResultAsBool(M(q));
            Reset(q);
		}
        return BoolArrayAsInt([ans]);
    }
}