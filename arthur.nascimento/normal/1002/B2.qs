namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
             let n = Length(qs);
			mutable ans = 0;
			for(i in 0..n-1){
				if(M(qs[i]) == One){
					set ans = ans + 1;
				}
			}
			if(ans == 1){
				return 1;
			}
			else {
				return 0;
			}
        }
    }
}