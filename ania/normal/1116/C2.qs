namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation checkAll(x : Qubit[], anc : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            for (p in 1..n-1) {
                
                for (i in 0..n-p-1) {
                    CNOT(x[i+p], x[i]);
                    X(x[i]);
                }
                Controlled X(x[0..n-p-1], anc[p-1]);
                for (j in 0..n-p-1) {
                    let i = n-p-1-j;
                    X(x[i]);
                    CNOT(x[i+p], x[i]);
                }
                
                //Message($"Checking period p={p}");
                //DumpMachine("");
                //using (a2 = Qubit[n-p]) {
                //    WithA(checkPeriod(x, _, p), Controlled X(_, anc[p]), a2);
                //}
                //DumpMachine("");
                X(anc[p-1]);
            }
        }
        adjoint auto;
    }
    
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using (anc = Qubit[n-1]) {
                WithA(checkAll(x, _), Controlled X(_, y), anc);
            }
            X(y);
        }
        adjoint auto;
    }
}