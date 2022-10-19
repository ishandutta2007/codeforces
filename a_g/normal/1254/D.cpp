#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 150005;
vector<int> G[N];
int sz[N], par[N], son[N], hpar[N], tin[N], tout[N], timer = 1;

long long bit[2*N], val[N];

void add(int x, long long l) {
  for (; x < 2*N; x += x&(-x)) bit[x] += l;
}

long long query(int x) {
  long long ans = 0;
  for (; x > 0; x -= x&(-x)) ans += bit[x];
  return ans;
}

void add_subtree(int v, long long l) {
  add(tin[v], l);
  add(tout[v], -l);
}

void dfs1(int v, int p) {
  par[v] = p;
  sz[v] = 1;
  tin[v] = timer++;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs1(u, v);
    if (sz[u] > sz[son[v]]) son[v] = u;
    sz[v] += sz[u];
  }
  tout[v] = timer++;
}

void dfs2(int v, int p, int hp) {
  hpar[v] = hp;
  for (int u: G[v]) {
    if (u == p) continue;
    if (u == son[v]) dfs2(u, v, hp);
    else dfs2(u, v, u);
  }
}

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);

  const int denom = expmod(n, MOD-2, MOD);
  while (q--) {
    int type, v;
    cin >> type >> v;
    if (type == 1) {
      int d;
      cin >> d;
      val[v] += d;
      if (son[v]) {
        add_subtree(son[v], -1LL*d*sz[son[v]]);
      }
      add_subtree(1, 1LL*d*sz[v]);
      add_subtree(v, 1LL*d*(n-sz[v]));
    }
    else {
      long long ans = query(tin[v]);
      v = hpar[v];
      while (v != 1) {
        ans -= val[par[v]]*sz[v];
        v = hpar[par[v]];
      }
      ans %= MOD;
      cout << ans*denom % MOD << '\n';
    }
  }
}