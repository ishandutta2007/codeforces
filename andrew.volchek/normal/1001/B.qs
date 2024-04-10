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

    operation Solve (qs : Qubit[], index : Int) : ()
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

    operation TestSolve (): String
    {
        body
        {
            using (register = Qubit[2])
            {
                Solve(register, 3);
                DumpRegister("dump.txt", register);
                ResetAll(register);
            }

            mutable mess = "123";
			return mess;
        }
    }
}