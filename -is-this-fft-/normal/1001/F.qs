namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
    body {
      mutable diffidx = -1;
      for (i in 0..Length(bits0)-1) {
        if (bits0[i] != bits1[i]) {
          set diffidx = i;
        }
      }

      let measurement = M(qs[diffidx]);
      if (measurement == Zero && bits0[diffidx] == false) {
        return 0;
      } elif (measurement == One && bits0[diffidx] == true) {
        return 0;
      } else {
        return 1;
      }
    }
  }
}