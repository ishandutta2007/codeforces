namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[]) : Int {
    body {
      for (i in 1..Length(qs) - 1) {
        CNOT(qs[i], qs[0]);
      }

      let measurement = M(qs[0]);

      if (measurement == Zero) {
        return 0;
      } else {
        return 1;
      }
    }
  }
}