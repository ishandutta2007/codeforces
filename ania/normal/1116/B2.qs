namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation Solve (x : Qubit) : Int {
        body (...) {
            let pi = PI();
            let theta = pi * 2.0 / 3.0;
            let Omega = R1(theta, _);
            let Y90 = Ry(pi/2.0, _);
            let Y90r = Ry(-pi/2.0, _);
            let X90 = Rx(pi/2.0, _);
            let Y60 = Ry(pi/3.0, _);
            let Y13 = Ry(2.0 * ArcCos(Sqrt(2.0/3.0)), _);
            mutable res = 0;
            using (y = Qubit()) {
                X90(x);
                Y90r(x);
                Y60(x);
                
                X(x);
                Controlled Y13([x],y);
                X(x);
                
                X(y);
                CNOT(y,x);
                X(x);
                Controlled Y90r([x],y);
                X(x);
                CNOT(y,x);
                X(y);
                
                //DumpMachine("");
                if (M(x) == Zero) {
                    if (M(y) == Zero) {
                        //Message($"Measured 00 = not C");
                        set res = 2;
                    } else {
                        //Message($"Measured 01 = not B");
                        set res = 1;
                    }
                } else {
                    if (M(y) == Zero) {
                        //Message($"Measured 10 = not A");
                        set res = 0;
                    } else {
                        //Message($"Measured 11 impossible");
                    }
                }
                
                Reset(y);
            }
            return res;
        }
    }
}