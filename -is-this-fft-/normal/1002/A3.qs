namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : () {
    body {
      mutable diffidx = -1;
      for (i in 0..Length(bits0) - 1) {
        if (bits0[i] != bits1[i]) {
          set diffidx = i;
        }
      }

      H(qs[diffidx]);
      for (i in 0..Length(qs) - 1) {
        if ((bits0[i] != bits1[i])) {
          if (i != diffidx) {
            CNOT(qs[diffidx], qs[i]);
          }
        }
      }

      for (i in 0..Length(qs) - 1) {
        if (bits0[i]) {
          X(qs[i]);
        }
      }
    }
  }
}