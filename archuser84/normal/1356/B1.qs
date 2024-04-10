namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (reg : LittleEndian) :  Unit is Adj+Ctl {
        body (...) {
            let N = Length(reg!);
            using(c = Qubit[N])
            {
                X(c[0]);
                for(i in 1..N-1) {
                    Controlled X([c[i-1], reg![i-1]], c[i]);        
				}
                for(i in N-1..-1..1) {
                    Controlled X([c[i]], reg![i]);
                    Controlled X([c[i-1], reg![i-1]], c[i]);        
				}
                Controlled X([c[0]], reg![0]);
                X(c[0]);
	    	}
    	}
    }
}