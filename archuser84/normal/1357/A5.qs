namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve1 (x : Int, U : (Qubit => Unit is Adj+Ctl)) : Result {
        mutable ans = Zero;
        using(q = Qubit()) {
            for(i in 1..x){U(q);}
            set ans = M(q);
            Reset(q);
		}
        return ans;
    }

    operation Solve (theta : Double, U : (Qubit => Unit is Adj+Ctl)) : Int {
        let k = Round(PI() / theta);
        let t = 10;
        for(i in 1..t) {
            if(Solve1(k, U) == One) {
                return 1;     
			} 
		}
        return 0;
    }
}