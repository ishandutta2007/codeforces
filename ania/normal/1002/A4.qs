namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            X(qs[0]);
            for (i in 0..n-2) {
                (Controlled Ry)([qs[i]], (2.0*ArcCos(1.0/Sqrt(ToDouble(n-i))), qs[i+1]));
            }
            for (i in n-2..-1..0) {
                for (j in i+1..n-1) {
                    CNOT(qs[j], qs[i]);
                }
            }
        }
    }
    operation Go (n : Int) : Bool {
        body {
            mutable res = false;
            using (qi = Qubit[n]) {
                Solve(qi);
                DumpMachine("");
                ResetAll(qi);
            }
            return res;
        }
    }

}