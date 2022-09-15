namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
			let N = Length(qs);
			mutable ind = -1;
			for(i in 0..N-1)
			{
				if(bits1[i] != bits0[i])
				{
					set ind = i;
				}
			}
			H(qs[ind]);
			for(i in 0..N-1)
			{
				if (i != ind)
				{
					if(bits1[i] ==bits0[i])
					{
						if(bits1[i])
						{
							X(qs[i]);
						}
					}
					else
					{
						if(bits1[i] == bits1[ind])
						{
							CNOT(qs[ind], qs[i]);
						}
						else
						{
							CNOT(qs[ind], qs[i]);
							X(qs[i]);
						}
					}
				}
			}
        }
    }
}