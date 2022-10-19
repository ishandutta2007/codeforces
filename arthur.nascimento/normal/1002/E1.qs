namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable res = new Int[N];		
            using (qs = Qubit[N]) {
		using (y = Qubit[1]) {
			for (i in 0..N-1) {
				H(qs[i]);
			}
			X(y[0]);
			H(y[0]);
			Uf(qs, y[0]);
			for (i in 0..N-1) {
				H(qs[i]);
			
			}
			mutable aux = 1;
			for (i in 0..N-1){
				set aux = aux * 2;
			}

			for (i in 0..N-1) {
				let v = M(qs[i]);
				if (v == One) {
					set res[i] = 1;
				}
				else {
					set res[i] = 0;
				}
			}
			ResetAll(y);
		}
		ResetAll(qs);
	   }
	   return res;
		
        }
    }
}