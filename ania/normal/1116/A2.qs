namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Core;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        body (...) {
            let n = Length(qs);
            
            mutable id = [0, 0, 0, 0];
            
            for (i in 0..n-1) {
                for (j in 0..3) {
                    if (id[j] == j) {
                        mutable bit0 = 0.0;
                        mutable bit1 = 0.0;
                        for (k in 0..3) {
                            if (id[k] == j) {
                                if (bits[k][i]) {
                                    set bit1 = bit1 + 1.0;
                                } else {
                                    set bit0 = bit0 + 1.0;
                                }
                            }
                        }
                        //Message($"i = {i}, j = {j}, bits = {bit0}, {bit1}, id = {id}");
                        let Op = Ry(2.0 * ArcCos(Sqrt(1.0 * (bit0) / (bit0+bit1))), _);
                        (ControlledOnBitString(bits[j][0..i-1], Op))(qs[0..i-1], qs[i]);
                    }
                }
                for (j in 0..3) {
                    if (id[j] == j) {
                        mutable other = -1;
                        for (k in 0..3) {
                            if (id[k] == j) {
                                if (bits[j][i] != bits[k][i]) {
                                    if (other == -1) {
                                        set other = k;
                                        set id[k] = k;
                                    } else {
                                        set id[k] = other;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}