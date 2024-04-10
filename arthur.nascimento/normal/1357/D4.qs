
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
        return ( (1,[0.275]), ClassifierStructure(), ([1.485,0.495,-0.2250000000000003,0.014999999999999694,-1.7650000000000003,0.43499999999999966,0.5349999999999997,-0.678], -0.02478 ));
    }
}