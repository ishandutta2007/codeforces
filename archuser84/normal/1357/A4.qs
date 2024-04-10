namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve(u : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using(q = Qubit[2]) {
			H(q[0]);
            Controlled u([q[0]], (2.0 * PI(), q[1]));
            H(q[0]);
            set ans = ResultAsInt([M(q[0])]);
            ResetAll(q);
		}
        return 1-ans;
	}
}