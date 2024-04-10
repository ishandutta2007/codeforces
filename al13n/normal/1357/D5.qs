namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.MachineLearning;

    function ToInt(r : Result) : Int {
        if (r == One) {
            return 1;
        } else {
            return 0;
        }
    }
    function BoolToInt(r : Bool) : Int {
        if (r) {
            return 1;
        } else {
            return 0;
        }
    }


    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [-.2,-1.5,3.5,.0,.0,1.6]),
                [ControlledRotation((2, new Int[0]), PauliX, 0),
                 ControlledRotation((0, new Int[0]), PauliY, 2),
                 ControlledRotation((2, new Int[0]), PauliY, 1),
                 ControlledRotation((3, [0, 2]), PauliX, 0)],
                ([PI(), -PI()*.49, PI()*.38], -.1));
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    using ((qs, a) = (Qubit[10], Qubit())) {
    //        X(qs[1]);
    //        X(qs[3]);
    //        X(qs[4]);
    //        X(qs[7]);
    //        X(qs[9]);
    //        X(qs[8]);
    //        Solve(qs, a);
    //        Message($"{M(a)}");
    //        ResetAll(qs + [a]);
    //    }
    //}
}