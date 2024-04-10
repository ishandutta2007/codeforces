
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
        operation Inc (reg : LittleEndian) :  Unit is Adj+Ctl {
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

    operation Solve(x : Qubit[], y : Qubit) : Unit is Adj+Ctl {
        using((qs, ans) = (Qubit[4], Qubit())) {
            mutable cnt = LittleEndian(qs);
            for(q in x) {
                Controlled Inc([q], cnt);
                X(q);
                Controlled Adjoint Inc([q], cnt);
                X(q);
			}
            ApplyToEachCA(X, cnt!);
            Controlled X(cnt!, y);
            ApplyToEachCA(X, cnt!);
            for(q in x) {
                X(q);
                Controlled Inc([q], cnt);
                X(q);
                Controlled Adjoint Inc([q], cnt);
			}
		}
	}

    operation Test(N : Int) : Unit {
        using((qs,q)=(Qubit[N],Qubit())) {
            ApplyToEach(X, qs);
            Solve(qs, q);
            ResetAll(qs);
            Reset(q);
		}
	}
}