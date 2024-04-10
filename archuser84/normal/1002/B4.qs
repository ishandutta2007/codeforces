namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Int {
        using(y = Qubit()) {
            X(y); H(y);
            H(qs[0]); H(qs[1]);
            (ControlledOnInt(0, X))(qs, y);
            H(qs[0]); H(qs[1]);
            let ans = ResultArrayAsInt([M(qs[1]),M(qs[0])]);
            Reset(y);
            return ans;
	    }
    }
}