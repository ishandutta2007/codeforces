namespace Solution {
    open Microsoft.Quantum.MachineLearning;
 
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [1.0, 1.0]), 
        [   ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((1, new Int[0]), PauliX, 0) ],
        ([7.460799999999999], 0.11495));
    }
}