namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[], b : Bool[][]) : Unit {
        let N = Length(qs);
        using(t = Qubit[2]){
            H(t[0]);
            H(t[1]);
            for(i in 0..N-1) {
                if(b[0][i]){(ControlledOnInt(0,X))(t,qs[i]);}
                if(b[1][i]){(ControlledOnInt(1,X))(t,qs[i]);}
                if(b[2][i]){(ControlledOnInt(2,X))(t,qs[i]);}
                if(b[3][i]){(ControlledOnInt(3,X))(t,qs[i]);}
			}
            (ControlledOnInt(BoolArrayAsInt(b[1]),X))(qs,t[0]);
            (ControlledOnInt(BoolArrayAsInt(b[2]),X))(qs,t[1]);
            (ControlledOnInt(BoolArrayAsInt(b[3]),X))(qs,t[0]);
            (ControlledOnInt(BoolArrayAsInt(b[3]),X))(qs,t[1]);
		}
    }
}