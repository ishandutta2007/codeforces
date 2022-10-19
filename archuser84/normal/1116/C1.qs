namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            ApplyToEach(X,x[0..2..Length(x)-1]);
            Controlled X(x, y);
            ApplyToEach(X,x);
            Controlled X(x, y);
            ApplyToEach(X,x[1..2..Length(x)-1]);
        }
        adjoint (...) {
            ApplyToEach(X,x[0..2..Length(x)-1]);
            Controlled X(x, y);
            ApplyToEach(X,x);
            Controlled X(x, y);
            ApplyToEach(X,x[1..2..Length(x)-1]);
		};
    }
}