namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;


    operation Solve (q : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        if (Length(q) == 2) {
            X(q[0]); Controlled X(q, output); 
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[1]);
        }

        if (Length(q) == 4) {
            X(q[0]); X(q[1]); Controlled X(q, output); 
            X(q[1]); X(q[2]); Controlled X(q, output); 
            X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[1]); X(q[2]); Controlled X(q, output); 
            X(q[2]); X(q[3]);
        }

        if (Length(q) == 6) {
            X(q[0]); X(q[1]); X(q[2]); Controlled X(q, output); 
            X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[5]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]);
        }

        if (Length(q) == 8) {
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[7]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]);
        }

        if (Length(q) == 10) {
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[0]); X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[1]); X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[6]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[2]); X(q[3]); X(q[4]); X(q[5]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[6]); X(q[7]); X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[4]); X(q[5]); X(q[6]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[3]); X(q[4]); X(q[5]); X(q[9]); Controlled X(q, output); 
            X(q[8]); X(q[9]); Controlled X(q, output); 
            X(q[7]); X(q[8]); Controlled X(q, output); 
            X(q[6]); X(q[7]); Controlled X(q, output); 
            X(q[5]); X(q[6]); Controlled X(q, output); 
            X(q[4]); X(q[5]); Controlled X(q, output); 
            X(q[5]); X(q[6]); X(q[7]); X(q[8]); X(q[9]);
        }
    }
    
    //@EntryPoint()
    operation RunQsharp () : Unit {
        using (q = Qubit()) {
            using (register = Qubit[4]) {
                X(register[0]);
                Solve(register, q);
                DumpRegister((), register);
                DumpRegister((), [q]);
                for (i in register) {
                    Reset(i);
                }
            }
            Reset(q);
        }
        using (q = Qubit()) {
            using (register = Qubit[4]) {
                X(register[2]);
                X(register[3]);
                Solve(register, q);
                DumpRegister((), register);
                DumpRegister((), [q]);
                for (i in register) {
                    Reset(i);
                }
            }
            Reset(q);
        }
        using (q = Qubit()) {
            using (register = Qubit[4]) {
                X(register[0]);
                X(register[1]);
                Solve(register, q);
                DumpRegister((), register);
                DumpRegister((), [q]);
                for (i in register) {
                    Reset(i);
                }
            }
            Reset(q);
        }
    }
}