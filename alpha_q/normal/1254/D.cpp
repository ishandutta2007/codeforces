#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int B = 400;
const int N = 150010;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

vector <int> g[N];
vector <pair <int, pair <int, int>>> normal[N];
int n, q, sub[N], in[N], out[N], ptr, block[B], f[N];

void go (int u = 1, int par = -1) {
  sub[u] = 1;
  if (~par) g[u].erase(find(g[u].begin(), g[u].end(), par));
  for (int v : g[u]) go(v, u), sub[u] += sub[v];
  sort(g[u].begin(), g[u].end(), [] (int i, int j) {return sub[i] < sub[j];});
}

void fix (int u = 1) {
  in[u] = ++ptr;
  for (int v : g[u]) fix(v);
  out[u] = ptr;
  for (int i = 0, j; i < g[u].size(); i = j) {
    j = i; while (j < g[u].size() and sub[g[u][i]] == sub[g[u][j]]) ++j;
    normal[u].emplace_back(sub[g[u][i]], make_pair(in[g[u][i]], out[g[u][j - 1]]));
  }
}

inline int add (int x, int y) {
  x += y; if (x >= MOD) x -= MOD; return x;
}

void update (int p, int v) {
  f[p] = add(f[p], v);
  block[p / B] = add(block[p / B], v);
}

void inc (int l, int r, int v) {
  if (v) update(l, v), update(r, MOD - v);
}

int query (int p) {
  int ret = 0, at = p / B;
  for (int i = 0; i < at; ++i) ret = add(ret, block[i]);
  for (int i = at * B; i < p; ++i) ret = add(ret, f[i]);
  return ret;
}

int main() {
  cin >> n >> q;
  ll inv = bigMod(n, -1);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go(); fix();
  while (q--) {
    int cmd, u; ll d;
    scanf("%d %d", &cmd, &u);
    if (cmd == 1) {
      scanf("%lld", &d);
      d *= inv, d %= MOD;
      int l = in[u], r = out[u];
      inc(0, l - 1, d * sub[u] % MOD);
      inc(r, n, d * sub[u] % MOD);
      inc(l - 1, l, d * n % MOD);
      for (auto it : normal[u]) {
        ll val = it.first; auto range = it.second;
        inc(range.first - 1, range.second, d * (n - val) % MOD);
      }
    } else {
      printf("%d\n", query(in[u]));
    }
  }
  return 0;
}