namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;
 
 
  
 
    function ClassifierStructure() : ControlledRotation[] {
        return [
        	ControlledRotation((0,new Int[0]), PauliY, 0)
        ];
    }
 
    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return ( ClassifierStructure(), ([3.1415], 0.0));
    }
 
    
 
}