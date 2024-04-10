namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
	{
		body
		{
			let n = Length(qs);
			mutable ret = 0;
			for (i in 0..n - 1) {
				if ((M(qs[i]) == Zero) == bits0[i]) {
					set ret = 1;
				}
			}
			return ret;
		}
	}
}