namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit is Adj)) : Unit {
        let size = 1 <<< N;

        //for (k in 0 .. size - 1) {
        for (k in size - 1 .. -1 .. 0) {
            using (qs = Qubit[N]) {
                // Prepare k-th basis vector
                let binary = IntAsBoolArray(k, N);

                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);

                // Apply the operation
                unitary(qs);

                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");

                //ResetAll(qs);
                // ResetAll may leave global phase behind.
                Adjoint unitary(qs);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
            }
        }
    }

    operation doit (qs : Qubit[]) : Unit is Adj {
        (ControlledOnInt(0, Ry))([qs[1], qs[2]], (1.5707963267948966, qs[0]));
        (ControlledOnInt(0, Rz))([qs[0], qs[2]], (-3.141592653589793, qs[1]));
        (ControlledOnInt(0, Ry))([qs[0], qs[2]], (1.9106332362490193, qs[1]));
        R(PauliI, 3.141592653589793, qs[0]);
        (ControlledOnInt(1, Rz))([qs[1], qs[2]], (-1.5707963267948966, qs[0]));
        (ControlledOnInt(1, Ry))([qs[1], qs[2]], (1.5707963267948966, qs[0]));
        (ControlledOnInt(1, Ry))([qs[0], qs[2]], (3.141592653589793, qs[1]));
        (ControlledOnInt(0, R1))([qs[1], qs[2]], (-0.7853981633974483, qs[0]));
        (ControlledOnInt(1, Rz))([qs[1], qs[2]], (0.7853981633974483, qs[0]));
        (ControlledOnInt(1, Ry))([qs[1], qs[2]], (1.5707963267948966, qs[0]));
        (ControlledOnInt(2, Ry))([qs[0], qs[2]], (3.141592653589793, qs[1]));
        (ControlledOnInt(2, Rz))([qs[0], qs[1]], (-0.13089969389957457, qs[2]));
        (ControlledOnInt(2, Ry))([qs[0], qs[1]], (1.5707963267948966, qs[2]));
        (ControlledOnInt(0, R1))([qs[0], qs[2]], (-1.5053464798451093, qs[1]));
        (ControlledOnInt(3, Ry))([qs[1], qs[2]], (3.141592653589793, qs[0]));
        (ControlledOnInt(3, Ry))([qs[0], qs[1]], (3.141592653589793, qs[2]));
        (ControlledOnInt(1, R1))([qs[1], qs[2]], (0.589048622548086, qs[0]));
        (ControlledOnInt(2, Ry))([qs[1], qs[2]], (3.141592653589793, qs[0]));
        (ControlledOnInt(3, Ry))([qs[1], qs[2]], (3.141592653589793, qs[0]));
        (ControlledOnInt(2, Rz))([qs[0], qs[2]], (2.2252947962927703, qs[1]));
        (ControlledOnInt(2, Ry))([qs[0], qs[2]], (1.5707963267948974, qs[1]));
        (ControlledOnInt(0, R1))([qs[0], qs[1]], (-0.4581489286485114, qs[2]));
        (ControlledOnInt(3, Ry))([qs[1], qs[2]], (3.141592653589793, qs[0]));
        (ControlledOnInt(3, Ry))([qs[0], qs[2]], (3.141592653589793, qs[1]));
        (ControlledOnInt(2, R1))([qs[1], qs[2]], (0.5890486225480855, qs[0]));
        (ControlledOnInt(3, Ry))([qs[1], qs[2]], (3.141592653589793, qs[0]));
        (ControlledOnInt(2, R1))([qs[0], qs[2]], (1.5707963267948966, qs[1]));
        (ControlledOnInt(3, R1))([qs[1], qs[2]], (1.5707963267948966, qs[0]));
    }

    operation Solve0 (q : Qubit) : Int {
        using ((a, b) = (Qubit(), Qubit())) {
            doit([q, a, b]);
            let r = MeasureInteger(LittleEndian([a, b]));
            ResetAll([a, b]);
            return r;
        }
    }

    operation doit2(qs:Qubit[]):Unit{
        X(qs[1]);
        Controlled Ry([qs[1]], (1.5707963267948966, qs[0]));
        X(qs[1]);
        X(qs[0]);
        Controlled Rz([qs[0]], (3.141592653589793, qs[1]));
        Controlled Ry([qs[0]], (1.2309594173407747, qs[1]));
        X(qs[0]);
        Controlled Ry([qs[1]], (3.141592653589793, qs[0]));
        Controlled Ry([qs[0]], (1.5707963267948974, qs[1]));
        X(qs[1]);
        Controlled R1([qs[1]], (-2.0943951023931957+3.141592653589793, qs[0]));
        X(qs[1]);
        Controlled Ry([qs[1]], (3.141592653589793, qs[0]));
        X(qs[0]);
        Controlled R1([qs[0]], (2.094395102393195+3.141592653589793, qs[1]));
        X(qs[0]);
        Controlled R1([qs[1]], (1.5707963267948966+3.141592653589793, qs[0]));

    }

    operation Solve (q : Qubit) : Int {
        using ((a) = (Qubit())) {
            doit2([q, a]);
            let r = MeasureInteger(LittleEndian([a, q]));
            ResetAll([a]);
            return r;
        }
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    //DumpUnitaryToFiles(3, doit);
    //    Message($"start");
    //    mutable w=0.;
    //    for (k in 0..2) {
    //        mutable cnt = 0;
    //        for (i in 1..333) {
    //            using (a = Qubit()) {
    //                H(a);
    //                R1(w / 3.*PI(), a);
    //                let r = Solve(a);
    //                if (r == k or r == 3) {
    //                    set cnt += 1;
    //                }
    //                Reset(a);
    //            }
    //        }
    //        Message($"{cnt}");
    //        set w += 2.;
    //    }
    //    Message($"end");
    //}
}