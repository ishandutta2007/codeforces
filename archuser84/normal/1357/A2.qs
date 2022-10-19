
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arithmetic;
 
    operation Solve(u : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using(q = Qubit[3]) {
            X(q[0]); X(q[2]);
            u(q[0..1]); u(q[1..2]);
            set ans = MeasureInteger(LittleEndian(q));
		}
        if(ans==5){return 0;}
        if(ans==3){return 1;}
        if(ans==7){return 2;}
        if(ans==6){return 3;}
        return -1;
	}

    operation uni(q : Qubit[]) : Unit is Adj+Ctl {
        SWAP(q[1],q[0]);
	}

    operation Test() : Int {
        return Solve(uni);
	}
}