namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
    }

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return (ClassifierStructure(), ([3.14], 0.0));
    }
}