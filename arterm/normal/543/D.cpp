#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int M = 200200;
typedef long long ll;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
  return x;
}

int mul(ll x, ll y) {
  return 1ll * x * y % mod;
}

int bin(int x, int a) {
  int y = 1;
  while (a) {
    if (a & 1)
      y = mul(x, y);
    x = mul(x, x);
    a >>= 1;
  }
  return y;
}

int inv(int x) {
  assert(x != 0);
  return bin(x, mod - 2);
}

int n;
vector<int> g[M];
int f[M];
int up[M];

void read() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u;
    cin >> u;
    --u;
    g[u].push_back(i);
  }
}

int dfs(int v) {
  f[v] = 1;
  for (int to : g[v])
    f[v] = mul(f[v], add(dfs(to), 1));
  return f[v];
}

void dfs_up(int v, int cnt) {
  up[v] = cnt;

  ll prod = add(cnt, 1);

  vector<int> pref;

  pref.push_back(1);
  for (int to : g[v])
    pref.push_back(mul(pref.back(), add(f[to], 1)));

  reverse(g[v].begin(), g[v].end());

  for (int i = 0; i < (int) g[v].size(); ++i) {
    int bon = mul(prod, pref[g[v].size() - 1 - i]);
    int to = g[v][i];
    dfs_up(to, bon);
    prod = mul(prod, add(f[to], 1));
  }
}


void kill() {
  dfs(0);
  dfs_up(0, 0);

  for (int v = 0; v < n; ++v) {
    int ans = 1;
    for (int u : g[v])
      ans = mul(ans, add(f[u], 1));
    ans = mul(ans, add(up[v], 1));
    cout << ans << " ";
  }

  cout << endl;
}

int main() {
  read();
  kill();
  return 0;
}