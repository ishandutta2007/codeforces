#include <iostream>

using namespace std;

void build (int n, int K, int A, int B) {
  int cntA = K / A;
  int cntB = (n - K) / B;

  int cur = 1;
  for (int i = 0; i < cntA; i++) {
    for (int j = cur; j < cur + A - 1; j++) {
      cout << j + 1 << " ";
    }
    cout << cur << " ";
    cur += A;
  }

  for (int i = 0; i < cntB; i++) {
    for (int j = cur; j < cur + B - 1; j++) {
      cout << j + 1 << " ";
    }
    cout << cur << " ";
    cur += B;
  }

  cout << endl;
}

int main () {
  int n, A, B;
  cin >> n >> A >> B;

  for (int k = 0; k <= n; k++) {
    if (k % A == 0 && (n - k) % B == 0) {
      build(n, k, A, B);
      return 0;
    }
  }

  cout << -1 << endl;
}