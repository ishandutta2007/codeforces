namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
     operation SampleQuantumRandomNumberGenerator() : Result {
        using (q = Qubit())  {  // Allocate a qubit.
            H(q);               // Put the qubit to superposition. It now has a 50% chance of being 0 or 1.
            return MResetZ(q);  // Measure the qubit value.
        }
    }
    operation SampleRandomNumberInRange(max : Int) : Int {
        mutable bits = new Result[0];
        for (idxBit in 1..BitSizeI(max)) {
            set bits += [SampleQuantumRandomNumberGenerator()];
        }
        let sample = ResultArrayAsInt(bits);
        return sample > max
           ? SampleRandomNumberInRange(max)
           | sample;
    }
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable chk = 0;
        using (q = Qubit()){
            for (test in 1..30) {
                mutable tp = test;
                Set(Zero, q);
                Rz(-theta*IntAsDouble(tp), q);
                for(ii in 1..tp){
                    unitary(q);
                }
                if(M(q) == One){
                    set chk = 1;
                }
            }
            Reset(q);
        }
        return chk;
    }

}