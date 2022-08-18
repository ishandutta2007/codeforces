namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[]) : Int {
    body {
      mutable allones = true;
      mutable allzeros = true;

      for (i in 0..Length(qs) - 1) {
        let measurement = M(qs[i]);
        if (measurement == Zero) {
          set allones = false;
        } else {
          set allzeros = false;
        }
      }

      if (allones || allzeros) {
        return 0;
      } else {
        return 1;
      }
    }
  }
}