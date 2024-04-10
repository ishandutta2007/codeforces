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
        return ( (1,[0.9]), ClassifierStructure(), ([-2.424,0.98879,4.221397343749999,-0.08775640625000167,-0.3518826562500017,3.1198435937499984,4.304217343749998,5.339861874999998], 0.056199482 ));
    }
}