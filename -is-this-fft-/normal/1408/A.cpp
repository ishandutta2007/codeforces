#include <iostream>

using namespace std;

const int MAX_N = 105;

int A [MAX_N], B [MAX_N], C [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }

  int last = -1;
  for (int i = 0; i < n - 1; i++) {
    if (A[i] == last) {
      cout << B[i] << " ";
      last = B[i];
    } else {
      cout << A[i] << " ";
      last = A[i];
    }
  }

  if (A[n - 1] != last && A[n - 1] != A[0]) {
    cout << A[n - 1] << '\n';
  } else if (B[n - 1] != last && B[n - 1] != A[0]) {
    cout << B[n - 1] << '\n';
  } else {
    cout << C[n - 1] << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
 
  for (int i = 0; i < testc; i++) {
    solve();
  }
}