namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve1 (reg : LittleEndian, k : Int) :  Unit is Adj+Ctl {
        body (...) {
            let N = Length(reg!);
            using(c = Qubit[N])
            {
                X(c[k]);
                for(i in k+1..N-1) {
                    Controlled X([c[i-1], reg![i-1]], c[i]);        
				}
                for(i in N-1..-1..k+1) {
                    Controlled X([c[i]], reg![i]);
                    Controlled X([c[i-1], reg![i-1]], c[i]);        
				}
                Controlled X([c[k]], reg![k]);
                X(c[k]);
	    	}
    	}
    }

    operation Solve (reg : LittleEndian) : Unit is Adj+Ctl {
        let N = Length(reg!);
        for(i in 0..N-1)
        { Solve1(reg, i); }
	}

    operation Test() : Unit {
        using(qs = Qubit[10]) {
            H(qs[5]);
            let x = LittleEndian(qs);
            Solve(x);
			Message(IntAsString(MeasureInteger(x)));
            ResetAll(qs);
		}
    }
}