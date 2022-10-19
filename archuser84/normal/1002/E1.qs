namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[]
    {
        mutable ans = new Int[N];
        using((x,y) = (Qubit[N], Qubit())) {
            ApplyToEach(H, x);
            X(y); H(y);
            Uf(x, y);
            ApplyToEach(H, x);
            for(i in 0..N-1) {
                set ans w/= i <- ResultArrayAsInt([M(x[i])]);
			}
            ResetAll(x);
            Reset(y);
		}
        return ans;
    }
}