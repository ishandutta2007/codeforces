#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const int INF = 1e9 + 5;

ll f[N][2];
int n, m, k, q, r[N], c[N], b[2][N], lt[N], rt[N];

ll cost (int sx, int sy, int ro, int side) {
  int st = lt[ro], en = rt[ro];
  if (side) sy = m + 1 - sy, swap(st, en), st = m + 1 - st, en = m + 1 - en;
  int stp = lower_bound(b[side] + 1, b[side] + q + 1, st) - b[side];
  int enp = lower_bound(b[side] + 1, b[side] + q + 1, en) - b[side];
  ll mn = INF;
  for (int i = max(1, stp - 3); i <= min(q, stp + 3); ++i) {
    int cur = b[side][i];
    mn = min(mn, (ll) abs(sy - cur) + abs(cur - en) + abs(en - st));
  }
  for (int i = max(1, enp - 3); i <= min(q, enp + 3); ++i) {
    int cur = b[side][i];
    mn = min(mn, (ll) abs(sy - cur) + abs(cur - en) + abs(en - st));
  }
  return mn + ro - sx;
}

int main() {
  cin >> n >> m >> k >> q;
  memset(lt, 63, sizeof lt);
  int mx = 0;
  for (int i = 1; i <= k; ++i) {
    scanf("%d %d", r + i, c + i);
    lt[r[i]] = min(lt[r[i]], c[i]);
    rt[r[i]] = max(rt[r[i]], c[i]);
    mx = max(mx, r[i]);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d", b[0] + i);
    b[1][i] = m + 1 - b[0][i];
  }
  int cnt = 0, at = -1;
  for (int i = n; i >= 1; --i) {
    if (lt[i] < INF) ++cnt, at = i;
  }
  if (cnt == 1 and at == 1) {
    cout << rt[1] - 1 << '\n';
    return 0;
  }
  sort(b[0] + 1, b[0] + q + 1);
  sort(b[1] + 1, b[1] + q + 1);
  f[mx][0] = f[mx][1] = 0;
  int last = mx;
  for (int i = mx - 1; i >= 1; --i) {
    if (lt[i] >= INF) continue;
    for (int j = 0; j < 2; ++j) {
      f[i][j] = min(cost(i, j ? rt[i] : lt[i], last, 0) + f[last][0], cost(i, j ? rt[i] : lt[i], last, 1) + f[last][1]);
    }
    last = i;
  }
  if (at == 1) {
    cout << rt[1] - 1 + f[1][1] << '\n';
    return 0;
  }
  cout << min(cost(1, 1, last, 0) + f[last][0], cost(1, 1, last, 1) + f[last][1]) << '\n';
  return 0;
}