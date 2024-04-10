#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2005;
const int M = 5e6 + 5;
const ll INF = 1e16 + 5;
const int MOD = 1e9 + 7;

#define m first
#define c second

inline bool bad (pair <ll, ll> a, pair <ll, ll> b, pair <ll, ll> c) {
  return (__int128) (a.c - b.c) * (c.m - a.m) >= (__int128) (a.c - c.c) * (b.m - a.m);
}

inline ll eval (pair <ll, ll> a, ll x) {
  return a.m * x + a.c;
}

inline ll sum (ll l, ll r) {
  return ((r * (r + 1) - l * (l - 1)) / 2) % MOD;
}

int n, m, q;
ll f[N][N], val[N][N], mx[N];
vector <pair <int, int>> g[N];
pair <ll, ll> lines[M], hull[M];

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  f[1][0] = 0;
  for (int i = 2; i <= n; ++i) {
    f[i][0] = -INF;
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      f[i][j] = -INF;
      for (auto it : g[i]) {
        int to = it.first, w = it.second;
        f[i][j] = max(f[i][j], f[to][j - 1] + w);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    ll cur = -INF;
    for (int j = 1; j <= n; ++j) cur = max(cur, f[j][i]);
    ans += cur, ans %= MOD;
  }
  for (int i = 1; i <= n; ++i) {
    mx[i] = -INF;
    for (auto it : g[i]) mx[i] = max(mx[i], (ll) it.second);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      val[i][j] = f[i][j] - j * mx[i];
    }
  }
  int tmp = m; m = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= tmp; ++j) {
      if (f[i][j] < -INF / 2) continue;
      lines[m++] = make_pair(mx[i], val[i][j]);
    }
  }
  sort(lines, lines + m);
  int sz = 0;
  for (int i = 0; i < m;) {
    int j = i;
    while (j < m and lines[j].m == lines[i].m) ++j;
    while (sz > 1 and bad(hull[sz - 2], hull[sz - 1], lines[j - 1])) --sz;
    hull[sz++] = lines[j - 1], i = j;
  }
  // for (int i = 0; i < sz; ++i) cout << hull[i].m << " " << hull[i].c << endl;
  int at = 0;
  while (at + 1 < sz and eval(hull[at], tmp + 1) <= eval(hull[at + 1], tmp + 1)) ++at;
  ll last = tmp + 1;
  // cout << ans << endl;
  for (int i = at; i < sz; ++i) {
    ll lo = last, hi = q;
    if (i + 1 < sz) {
      while (lo < hi) {
        ll mid = lo + hi + 1 >> 1;
        if (eval(hull[i], mid) > eval(hull[i + 1], mid)) lo = mid;
        else hi = mid - 1;
      }
    } else {
      lo = q;
    }
    ll lt = last, rt = lo;
    if (lt > rt) break;
    ll cur = ((rt - lt + 1) * (hull[i].c % MOD) + hull[i].m * sum(lt, rt)) % MOD;
    if (cur < 0) cur += MOD;
    ans += cur, ans %= MOD, last = lo + 1;
  }
  cout << ans << '\n';
  return 0;
}