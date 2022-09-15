namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let N = Length(qs);
			mutable cnt = 0;
			for(i in 0..N-1)
			{
				if(M(qs[i]) == One)
				{
					set cnt = cnt + 1;
				}
			}
			if(cnt == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
        }
    }
}