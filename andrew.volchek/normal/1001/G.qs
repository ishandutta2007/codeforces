// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.


namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation SolveB (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if ((index &&& 1) > 0) {
                X(qs[0]);
            }
            if ((index &&& 2) > 0) {
                X(qs[1]);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }

    operation SolveC (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            H(qs[0]);
            for (i in 1..n-1) {
                CNOT(qs[i - 1], qs[i]);
            }
        }
    }

    operation SolveD (qs : Qubit) : Int {
        body {
            H(qs);
            let result = M(qs);
            if (result == Zero) {
                return +1;
            } else {
                return -1;
            }
        }
    }

    operation SolveE (qs : Qubit[]) : Int {
        body {
            (Adjoint CNOT)(qs[0], qs[1]);
            H(qs[0]);
            let m0 = M(qs[0]);
            let m1 = M(qs[1]);
            mutable result = 0;
            if (m1 == One) {
                set result = 2;
            }
            if (m0 == One) {
                set result = result + 1;
            }
            return result;
        }
    }

    operation SolveF (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        body {
            let n = Length(qs);
            for (i in 0 .. n - 1) {
                let r = M(qs[i]);
                if (bits0[i] != bits1[i]) {
                    if (bits0[i] == (r == One)) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            CNOT(x[k], y);
        }
    }

    operation TestSolve () : String
    {
        body
        {
            using (register = Qubit[2])
            {
                // SolveB(register, 3);
                // SolveC(register);
                // Set(Zero, register[0]);
                // H(register[0]);
                // let result = Solve(register[0]);
                // if (result != -1) {
                //     fail "32432";
                // }
                // let idx = 2;
                // SolveB(register, idx);
                // if (Solve(register) != idx) {
                //     fail "43r5";
                // }
                DumpRegister("dump.txt", register);
                ResetAll(register);
            }

            mutable mess = "123";
			return mess;
        }
    }
}