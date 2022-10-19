namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (u : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = false;
        using((q,r) = (Qubit(),Qubit())) {
            u([q,r]);
            set ans = not ResultAsBool(M(r));
            Reset(q);
            Reset(r);
		}
        return BoolArrayAsInt([ans]);
    }
}