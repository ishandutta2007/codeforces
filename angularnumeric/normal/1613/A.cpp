
#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long SZ = 1e6 + 5;
const long long mod = 1e9 + 7;
long long n, x1, x2, p1, p2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0,
            t = 0;
  string s, s1, s2;
  cin >> tc;
  while (tc--) {
    cin >> x1 >> p1 >> x2 >> p2;
    x = x1, y = x2, z = p1 - p2;
    if (z > 0) {
      while (z--) {
        x1 *= 10;
        if (x1 > 1000000) break;
      }
    } else if (z < 0) {
      z *= -1;
      while (z--) {
        x2 *= 10;
        if (x2 > 1000000) break;
      }
    }
    p = max(x1, x2);
    q = min(x1, x2);
    if (p == q) {
      cout << "=" << "\n";
    } else if (p > q) {
      if (x1 > x2)
        cout << ">"
             << "\n";
      else
        cout << "<"
             << "\n";
    } else {
      if (x1 < x2)
        cout << "<"
             << "\n";
      else
        cout << ">"
             << "\n";
    }
  }
  return 0;
}