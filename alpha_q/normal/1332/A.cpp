#include <bits/stdc++.h>

using namespace std;

inline bool good (long long x, long long l, long long r, long long lt, long long rt) {
  l -= x, r -= x;
  if (l == r) return lt == 0 and rt == 0;
  return l <= rt - lt and rt - lt <= r;
}

int t;
long long a, b, c, d, p, q, x[2], y[2];

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    cin >> p >> q >> x[0] >> y[0] >> x[1] >> y[1];
    puts(good(p, x[0], x[1], a, b) and good(q, y[0], y[1], c, d) ? "Yes" : "No");
  }
  return 0;
}