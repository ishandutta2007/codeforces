namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
    operation Givens (qs : Qubit[], id : Int) : Unit {
        body (...) {
            let n = Length(qs);
            
            let OpM = IntegerIncrementLE(-id, _);
            (ControlledOnInt(0, OpM))(qs[2..n-1], LittleEndian(qs[0..1]));
            (ControlledOnInt(0, H))(qs[1..n-1], qs[0]);
            let OpP = IntegerIncrementLE(id, _);
            (ControlledOnInt(0, OpP))(qs[2..n-1], LittleEndian(qs[0..1]));
            
        }
    }
    
    operation Hessenberg3 (qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            let m = 2^n;
            
            //IntegerIncrementLE(-(m-2), LittleEndian(qs));
            IntegerIncrementLE(1, LittleEndian(qs));
            
            for (i in 0..m-2) {
                //IntegerIncrementLE(-id, LittleEndian(qs));
                IntegerIncrementLE(1, LittleEndian(qs));
                (ControlledOnInt(0, H))(qs[1..n-1], qs[0]);
                //Givens(qs, m-2-i);
            }
            //IntegerIncrementLE(-1, LittleEndian(qs));
        }
        adjoint auto;
        controlled auto;
    }
    
    operation Add1(qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            for (i in 0..n-1) {
                Controlled X(qs[0..n-i-2], qs[n-i-1]);
            }
        }
    }
    
    operation Sub1(qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            for (i in 0..n-1) {
                Controlled X(qs[0..i-1], qs[i]);
            }
        }
    }
    
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            
            
            let m = 2^n;
            
            //IntegerIncrementLE(-(m-2), LittleEndian(qs));
            Add1(qs);
            
            for (i in 0..m-2) {
                //IntegerIncrementLE(-id, LittleEndian(qs));
                Add1(qs);
                (ControlledOnInt(0, H))(qs[1..n-1], qs[0]);
                //Givens(qs, m-2-i);
            }
            
            //Sub1(qs);
            //(ControlledOnInt(0, H))(qs[1..n-1], qs[0]);
            //Add1(qs);
            
            //if (n <= 3) {
            //    Hessenberg3(qs);
            //    return ();
            //}
            //
            //let m = 2^n;
            //
            //(ControlledOnInt(0, Hessenberg3))([qs[n-1]], qs[0..n-2]);
            //IntegerIncrementLE(-(m/2-1), LittleEndian(qs));
            //(ControlledOnInt(0, H))(qs[1..n-1], qs[0]);
            //IntegerIncrementLE((m/2-1), LittleEndian(qs));
            //(ControlledOnInt(1, Hessenberg3))([qs[n-1]], qs[0..n-2]);
            
        }
    }
}