namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
		using ( q = Qubit() ) { 
			repeat {
			H(qs[0]);
			H(qs[1]);
				CCNOT(qs[0], qs[1], q);
				let r = M(q);
			} until (r == Zero)
			fixup{
			
			}
		}
    }
}