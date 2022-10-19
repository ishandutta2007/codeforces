namespace Solution {
    open Microsoft.Quantum.MachineLearning;

	function ClassifierStructure() : ControlledRotation[] {

        return [

           ControlledRotation((0, new Int[0]), PauliX, 4),

            ControlledRotation((0, new Int[0]), PauliZ, 5),

            ControlledRotation((1, new Int[0]), PauliX, 6),

            ControlledRotation((1, new Int[0]), PauliZ, 7),

            ControlledRotation((0, [1]), PauliX, 0),

            ControlledRotation((1, [0]), PauliX, 1),

            ControlledRotation((1, new Int[0]), PauliZ, 2),

            ControlledRotation((1, new Int[0]), PauliX, 3)

        ];

    }

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ( (4,[1.0,100.0]), ClassifierStructure(), ([0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0], 0.29715));
    }
}