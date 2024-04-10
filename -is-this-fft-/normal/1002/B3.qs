namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[]) : Int {
    body {
      H(qs[0]);
      H(qs[1]);

      mutable ans = 0;
      let meas1 = M(qs[0]);
      if (meas1 == One) {
        set ans = ans + 2;
      }

      let meas2 = M(qs[1]);
      if (meas2 == One) {
        set ans = ans + 1;
      }

      return ans;
    }
  }
}