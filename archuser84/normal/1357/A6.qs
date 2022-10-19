namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using((c, t) = (Qubit(), Qubit())) {
            H(c); CNOT(c, t); H(t);
            U(t);
            H(t); CNOT(c, t);
            H(c); CNOT(t, c);
            set ans = MeasureInteger(LittleEndian([c, t]));
            ResetAll([c, t]);
		}
        return ans;
	}
}