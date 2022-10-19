#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int q;
    cin >> q;
    long long f[2] = {0, 0};
    bool g[2] = {0, 0};
    while (q--) {
      int d, k;
      string x;
      cin >> d >> k >> x;
      d--;
      for (char c: x) {
        if (c != 'a') g[d] = 1;
        else f[d] += k;
      }
      cout << (g[1] || (f[0] < f[1] && !g[0]) ? "YES" : "NO") << '\n';
    }
  }
}