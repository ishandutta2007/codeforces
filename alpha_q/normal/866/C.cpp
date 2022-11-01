#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 53;
const int R = 5005;

int n, r;
ld f[N], s[N];
ld p[N], q[N];
ld dp[N][R], mid;
bitset <R> vis[N];

ld call (int at, int rem) {
  if (rem < 0) return mid; 
  if (at > n) return 0;
  ld &ret = dp[at][rem];
  if (vis[at][rem]) return ret;
  vis[at][rem] = 1;
  return ret = min(mid, p[at] * (f[at] + call(at + 1, rem - f[at])) + q[at] * (s[at] + call(at + 1, rem - s[at])));
}

int main() {
  scanf("%d %d", &n, &r);
  for (int i = 1; i <= n; ++i) {
    scanf("%Lf %Lf %Lf", f + i, s + i, p + i);
    p[i] /= 100.0, q[i] = 1.0 - p[i];
  }
  ld lo = 0, hi = 1e16;
  for (int it = 0; it < 100; ++it) {
    mid = (lo + hi) / 2.0;
    for (int i = 0; i <= n; ++i) {
      vis[i].reset();
    }
    if (call(1, r) < mid) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%0.12f\n", (double) lo);
  return 0;
}