namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (q : Qubit) : Int {
    body {
      Ry(0.7853981, q);

      let measurement = M(q);
      if (measurement == Zero) {
        return 0;
      } else {
        return 1;
      }
    }
  }
}