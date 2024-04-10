namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            //bx + 1 - b - x + bx  = 1 + b + x
			let N = Length(x);
			for(i in 0..N-1)
			{
				if(b[i] == 0)
				{
					X(y);
				}
				CNOT(x[i], y);
			}
        }
    }
}