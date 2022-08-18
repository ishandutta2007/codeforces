namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int {
        body {
          CNOT(qs[0], qs[1]);
          H(qs[0]);
          let bit1 = M(qs[0]);
          let bit2 = M(qs[1]);
          mutable ans = 0;
          if (bit1 == One) {
            set ans = ans + 1;
          }
          if (bit2 == One) {
            set ans = ans + 2;
          }
          return ans;
        }
    }
}