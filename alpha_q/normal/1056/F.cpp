#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long double ld;

const int N = 105;
const int M = 1005;
const ld INF = 1e16;
const ld SHIFT = 1e8;

pair <int, int> d[N];
int t, cs, n, vis[N][N][M];
ld c, T, f[N][N][M], pwr[N];

int main() {
  pwr[0] = SHIFT;
  for (int i = 1; i < N; ++i) {
    pwr[i] = pwr[i - 1] * 0.9;
  }
  cin >> t;
  for (cs = 1; cs <= t; ++cs) {
    scanf("%d", &n);
    double cc, tt;
    scanf("%lf %lf", &cc, &tt);
    c = cc, T = tt;
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &d[i].first, &d[i].second);
      tot += d[i].second;
    }
    sort(d + 1, d + n + 1);
    for (int idx = 0; idx <= n; ++idx) {
      for (int pts = 0; pts <= tot; ++pts) {
        f[n + 1][idx][pts] = INF;
      }
    }
    f[n + 1][0][0] = 0;
    for (int at = n; at >= 1; --at) {
      for (int idx = 0; idx <= n; ++idx) {
        for (int pts = 0; pts <= tot; ++pts) {
          f[at][idx][pts] = f[at + 1][idx][pts];
          if (pts >= d[at].second and idx) f[at][idx][pts] = min(f[at][idx][pts], SHIFT * d[at].first / pwr[idx] + f[at + 1][idx - 1][pts - d[at].second]);
        }
      }
    }
    int found = 0;
    for (int pts = tot; pts >= 0; --pts) {
      for (int idx = 0; idx <= n; ++idx) {
        ld cur = f[1][idx][pts];
        if (cur >= INF / 2.0) continue;
        ld at = max(ld(0), (sqrtl(cur * c) - 1) / c);
        ld val = at + cur / (1 + at * c) + 10 * idx;
        if (val <= T) {
          printf("%d\n", pts);
          found = 1;
          break;
        }
      }
      if (found) break;
    }
  }
  return 0;
}