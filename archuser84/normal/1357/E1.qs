namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve (p : Int, x : LittleEndian) : Unit is Adj+Ctl {
        let n = Length(x!);
        let k = p % (1 <<< n);
        for(i in 1..k){
            QFTLE(x);  
		}
    }
}