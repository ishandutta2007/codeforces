namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
		body {
			mutable b = new Int[N];
			for(i in 0..N-1) {
				set b[i] = 0;
			}
			using(qs = Qubit[N]) {
				using(res = Qubit[1]) {
					for(i in 0..N-1) {
						X(res[0]);
					}
					Uf(qs, res[0]);
					if(M(res[0]) == One) {
						set b[0] = 1;
					}
					Reset(res[0]);
				}
			}
			return b;
		}
	}
}