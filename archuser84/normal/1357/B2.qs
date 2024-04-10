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
 
    operation miniSolve(x : Qubit[], y : Qubit) : Unit is Adj+Ctl {
        let N = Length(x);
        using(qs = Qubit[3]) {
            mutable cnt = LittleEndian(qs);
            for(i in 0..N-1) {
                if(i%2==0){Controlled Inc([x[i]], cnt);}
                if(i%2==1){Controlled Adjoint Inc([x[i]], cnt);}
			}
            ApplyToEachCA(X, cnt!);
            Controlled X(cnt!, y);
            ApplyToEachCA(X, cnt!);
            for(i in 0..N-1) {
                if(i%2==0){Controlled Adjoint Inc([x[i]], cnt);}
                if(i%2==1){Controlled Inc([x[i]], cnt);}
			}
		}
	}

    operation Solve(x : Qubit[], y : Qubit) : Unit is Adj+Ctl {
        let N = Length(x);
        using(qs = Qubit[4]) {
            X(qs[0]); X(qs[3]);
            mutable cnt = LittleEndian(qs);
            for(i in 0..N-1) {
                if(i%2==0){Controlled Inc([x[i]], cnt);}
                if(i%2==1){Controlled Adjoint Inc([x[i]], cnt);}
			}
            miniSolve(cnt!, y);
            for(i in 0..N-1) {
                if(i%2==0){Controlled Adjoint Inc([x[i]], cnt);}
                if(i%2==1){Controlled Inc([x[i]], cnt);}
			}
            X(qs[0]); X(qs[3]);
		}
	}
 
    operation Test(N : Int, k : Int) : Int {
        mutable ans = 0;
        using((qs,q)=(Qubit[N],Qubit())) {
            mutable x = k;
            for(i in 0..N-1) {
                if(x%2==1){X(qs[i]);}
                set x = x/2;
			}
            Solve(qs, q);
            set ans = ResultAsInt([M(q)]);
            ResetAll(qs);
            Reset(q);
		}
        return ans;
	}
}