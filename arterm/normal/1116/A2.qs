namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Prep (qs : Qubit[], mask : Int) : Unit {
        if (mask % 2 == 0) {
            X(qs[0]);
        }
        if ((mask / 2) % 2 == 0) {
            X(qs[1]);
        }
    }

    operation Apply (qs : Qubit[], bits : Bool[]) : Unit {
        let n = Length(qs);
        for (i in 0..n-1) {
            if (bits[i] == false) {
                X(qs[i]);
            }
        }
    }

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        let n = Length(qs);
        
        using (anc = Qubit[2]) {
            ApplyToEach(H, anc);

            for (mask in 0..3) {
                Prep(anc, mask);
                for (i in 0..n-1) {
                    if (bits[mask][i]) {
                        CCNOT(anc[0], anc[1], qs[i]);
                    }
                }
                Prep(anc, mask);
            }

            for (mask in 0..3) {
                Apply(qs, bits[mask]);
                if (mask % 2 == 1) {
                    (Controlled X)(qs, anc[0]);
                }
                if ((mask / 2) % 2 == 1) {
                    (Controlled X)(qs, anc[1]);
                }
                Apply(qs, bits[mask]);
            }
            ResetAll(anc);
        }
    }


    operation Test (n : Int) : Int[] {
        mutable measurment = new Int[n];
        let bits = 
        [
            [ true, false,  true],
            [ true,  true, false],
            [ true,  true,  true],
            [ false,  true, false]
        ];

        using (register = Qubit[n]) {
            let x = register[0..(n-1)];
            Solve(x, bits);
            DumpMachine("dump.txt");
            for (i in 0..n-1) {
                if (M(register[i]) == One) {
                    set measurment[i] = 1;
                }
            }
            ResetAll(register);
        }
        return measurment;
    }

}