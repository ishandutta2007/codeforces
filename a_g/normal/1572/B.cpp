#include <bits/stdc++.h>
using namespace std;

void p(int a, int b) {
  for (int j = a; j < b; j += 2) {
    cout << j << " ";
  }
  for (int j = b-4; j > a-1; j-= 2) {
    cout << j << " ";
  }
}
int main () {
  int T, n, k, t, c, o;
  cin >> T;
  while (T--) {
    cin >> n;
    t = 0;
    c = -1;
    for (int i = 0; i < n; i++) {
      cin >> k;
      t ^= k;
      if (!(t || i&1)) {
        c = i;
      }
    }
    if (t || (!(n&1) && c == -1)) {
      cout << "NO" << '\n';
    }
    else {
      cout << "YES" << '\n';
      if (n & 1) {
        cout << n-2 << '\n';
        p(1, n);
      }
      else {
        o = n-4;
        if (c == 0 || c == n-2) {
          o = n-3;
        }
        cout << o << '\n';
        p(1, c+1);
        p(c+2, n);
      }
      cout << '\n';
    }
  }
}