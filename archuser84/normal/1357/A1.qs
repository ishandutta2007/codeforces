namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve(u : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using(q = Qubit[2]) {
			X(q[1]);
            u(q);
            set ans = ResultAsInt([M(q[0])]);
            ResetAll(q);
		}
        return ans;
	}
}