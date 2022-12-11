namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            let n2 = 2^n-1;
            (ControlledOnInt(0, X))(x, y);
            if (n >= 3 && n<9) {
                for (i in 0..n-1) {
                    let i2 = 2^i;
                    for (j in 0..i-1) {
                        let j2 = 2^j;
                        for (k in 0..j-1) {
                            let k2 = 2^k;
                            (ControlledOnInt(i2 + j2 + k2, X))(x, y);
                        }
                    }
                }
            }
            if (n == 6) {
                (ControlledOnInt(n2, X))(x, y);
            }
            if (n == 7) {
                for (i in 0..n-1) {
                    let i2 = 2^i;
                    (ControlledOnInt(n2 - i2, X))(x, y);
                }
            }
            if (n == 8) {
                for (i in 0..n-1) {
                    let i2 = 2^i;
                    for (j in 0..i-1) {
                        let j2 = 2^j;
                        (ControlledOnInt(n2 - i2 - j2, X))(x, y);
                    }
                }
            }
            if (n == 9) {
                
                for (i in 0..n-1) {
                    X(x[i]);
                }
                
                //Controlled X(x, y);
                
                for (i in 0..n-1) {
                    X(x[i]);
                    for (j in 0..i-1) {
                        X(x[j]);
                        for (k in 0..j-1) {
                            X(x[k]);
                            Controlled X(x,y);
                            X(x[k]);
                        }
                        X(x[j]);
                    }
                    X(x[i]);
                }
                
                for (i in 0..n-1) {
                    X(x[i]);
                }
                
                Controlled X(x, y);
                
                for (i in 0..n-1) {
                    X(x[i]);
                    for (j in 0..i-1) {
                        X(x[j]);
                        for (k in 0..j-1) {
                            X(x[k]);
                            Controlled X(x,y);
                            X(x[k]);
                        }
                        X(x[j]);
                    }
                    X(x[i]);
                }
            }
        }
        adjoint auto;
    }
}