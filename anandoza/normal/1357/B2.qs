namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        if (Length(q) == 1) {
            X(q[0]); Controlled X(q, output); 
            X(q[0]);
        }
        
        if (Length(q) == 2) {
             Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]);
        }
        
        if (Length(q) == 3) {
            X(q[0]); Controlled X(q, output); 
            X(q[0]); X(q[2]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]);
        }
        
        if (Length(q) == 4) {
             Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]);
        }
        
        if (Length(q) == 5) {
            X(q[0]); Controlled X(q, output); 
            X(q[0]); X(q[2]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[1]); X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]);
        }
        
        if (Length(q) == 6) {
             Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]);
        }
        
        if (Length(q) == 7) {
            X(q[0]); Controlled X(q, output); 
            X(q[0]); X(q[2]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[3]); X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]);
        }
        
        if (Length(q) == 8) {
             Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[4]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[2]); X(q[4]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]);
        }
    }
}