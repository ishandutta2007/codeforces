namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let len = Length(inputs);
        for (i in 0 .. (1 <<< len)-1) {
            if (i%3 == 0) {
                for (j in 0 .. len-1) {
                    if ((i &&& (1 <<< j)) == 0) {
                        X(inputs[j]);
                    }
                }
                Controlled X(inputs, output);
                for (j in 0 .. len-1) {
                    if ((i &&& (1 <<< j)) == 0) {
                        X(inputs[j]);
                    }
                }
            }
        }
    }
}