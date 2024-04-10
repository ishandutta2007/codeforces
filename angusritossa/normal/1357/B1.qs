namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (qs = Qubit[4]) {
            for (qubit in inputs) {
                // this is just += qubit
                Controlled X([qubit, qs[0], qs[1], qs[2]], qs[3]);
                Controlled X([qubit, qs[0], qs[1]], qs[2]);
                Controlled X([qubit, qs[0]], qs[1]);
                Controlled X([qubit], qs[0]);
            }
            // now we want to check if qs == the required bit pattern
            if (Length(inputs) == 2) {
                X(qs[1]);
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 4) {
                X(qs[0]);
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 6) {
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 8) {
                X(qs[0]);
                X(qs[1]);
                X(qs[3]);
            }
            if (Length(inputs) == 10) {
                X(qs[1]);
                X(qs[3]);
            }
            Controlled X(qs, output);
            if (Length(inputs) == 2) {
                X(qs[1]);
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 4) {
                X(qs[0]);
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 6) {
                X(qs[2]);
                X(qs[3]);
            }
            if (Length(inputs) == 8) {
                X(qs[0]);
                X(qs[1]);
                X(qs[3]);
            }
            if (Length(inputs) == 10) {
                X(qs[1]);
                X(qs[3]);
            }
            for (qubit in inputs) {
                // this is just -= qubit
                X(qs[0]);
                X(qs[1]);
                X(qs[2]);
                Controlled X([qubit, qs[0], qs[1], qs[2]], qs[3]);
                X(qs[2]);
                Controlled X([qubit, qs[0], qs[1]], qs[2]);
                X(qs[1]);
                Controlled X([qubit, qs[0]], qs[1]);
                X(qs[0]);
                Controlled X([qubit], qs[0]);
            }
        }
    }
}