#include <bits/stdc++.h>
using namespace std;

const int M = 200;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bool neg = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      if (val < 0) neg = 1;
    }
    if (neg) cout << "No" << endl;
    else {
      cout << "Yes" << endl;
      cout << M+1 << endl;
      for (int k = 0; k <= M; k++) {
        cout << k << " ";
      }
      cout << endl;
    }
  }
}