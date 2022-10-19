#include <bits/stdc++.h>
using namespace std;

const int M = 17;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    int n = r-l+1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x = 0;
    vector<int> Z;
    for (int i = M-1; i >= 0; i--) {
      int expected = 0;
      for (int j = l; j <= r; j++) {
        if (j&(1<<i)) expected++;
      }
      int c = 0;
      for (int val: a) {
        if (val&(1<<i)) c++;
      }
      if (c != expected) {
        assert(c+expected == n);
        x ^= (1<<i);
      }
      if (expected != 0 && expected != n) {
        for (int& val: a) val ^= x;
        for (int j = i-1; j >= 0; j--) {
          int d = 0;
          int e = 0;
          for (int val: a) {
            if (val&(1<<i)) {
              if (val&(1<<j)) d++;
              else d--;
            }
            else {
              if (val&(1<<j)) e++;
              else e--;
            }
          }
          if (d > 0 || e < 0) x ^= (1<<j);
        }
        break;
      }
    }
    cout << x << '\n';
  }
}