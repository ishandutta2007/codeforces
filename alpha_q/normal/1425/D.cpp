#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2010;
const int MOD = 1e9 + 7;

inline ll add (ll x, ll y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline ll sub (ll x, ll y) {
  return x < y ? x - y + MOD : x - y;
}

inline ll mul (ll x, ll y) {
  return x * y % MOD;
}

bitset <N> adj[N];
ll val[N], c[N][N];
int n, m, r, x[N], y[N];

inline ll comb (ll x, ll y) {
  if (x < y or y < 0) return 0; return c[x][y];
}

int main() {
  for (int i = 0; i < N; ++i) c[i][0] = 1;
  for (int i = 1; i < N; ++i) for (int j = 1; j <= i; ++j) {
    c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  cin >> n >> m >> r;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %lld", x + i, y + i, val + i);
  }
  for (int i = 1; i <= n; ++i) {
    adj[i][i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= r) {
        adj[i][j] = adj[j][i] = 1;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int nei_i = adj[i].count();
    ans = add(ans, mul(sub(comb(n, m), comb(n - nei_i, m)), mul(val[i], val[i])));
    for (int j = i + 1; j <= n; ++j) {
      ll cur = mul(val[i], val[j]);
      int nei_j = adj[j].count(), com = (adj[i] & adj[j]).count();
      ll ways = sub(comb(n, m), comb(n - com, m)); // common present
      int dis_i = nei_i - com, dis_j = nei_j - com;
      ll noCom = add(sub(comb(n - com, m), add(comb(n - com - dis_i, m), comb(n - com - dis_j, m))), comb(n - com - dis_i - dis_j, m));
      ways = add(ways, noCom);
      ans = add(ans, mul(2 * ways % MOD, cur));
    }
  }
  cout << ans << '\n';
  return 0;
}