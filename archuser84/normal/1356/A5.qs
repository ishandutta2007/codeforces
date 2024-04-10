namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (u : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = false;
        using((q,r) = (Qubit(),Qubit())) {
            H(q);
            Controlled u([q],r);
            Controlled Z([q],r);
            H(q);
            set ans = ResultAsBool(M(q));
            Reset(q);
		}
        return BoolArrayAsInt([ans]);
    }
}