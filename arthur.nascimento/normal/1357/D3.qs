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
        return ( (1,[1.0]), ClassifierStructure(), ([0.0,3.03999598,5.291119772382822,6.522125128601572,6.489860542882822,6.303229520351571,6.275299501132822,7.227924541601571], 0.09945 ));
    }
}