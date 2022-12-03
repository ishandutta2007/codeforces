/*


Q.E.D.

start thinking: 22:30
BULB: 22:35
result of thinking: Pure.

start coding: 22:35
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 1000005
const int inf = 0x3f3f3f3f;

int n, dep[maxn];

namespace vTree {
  vector<int> chi[maxn];
  bool imp[maxn];
  ll f[maxn][2];

  // void print() {
  //   for (int i = 1; i <= n; i++) {
  //     cout << "chi[" << i << "]: ";
  //     for (auto u : chi[i]) {
  //       cout << u << " ";
  //     }
  //     cout << endl;
  //   }
  //   system("pause");
  // }

  bool check(int u) {
    for (auto v : chi[u]) {
      if (imp[u] && imp[v] && dep[v] == dep[u] + 1)
        return false;
      if (!check(v))
        return false;
    }
    return true;
  }

  void dp(int u) {
    ll sum0 = 0, sum1 = 0;
    for (auto v : chi[u]) {
      dp(v);
      sum0 += f[v][0];
      sum1 += f[v][1];
      // chmin(sum0, inf);
    }
    if (imp[u]) {
      f[u][0] = inf, f[u][1] = 0;
      for (auto v : chi[u]) {
        f[u][1] += min(f[v][0], f[v][1] + 1);
      }
    } else {
      f[u][0] = f[u][1] = min(sum1 + 1, sum0);
      for (auto v : chi[u]) {
        chmin(f[u][1], sum0 - f[v][0] + f[v][1]);
      }
    }
  }
}

int dfn[maxn], ind, par[17][maxn];
vector<int> adj[maxn];

void dfs(int u, int f) {
  dfn[u] = ++ind;
  par[0][u] = f;
  dep[u] = dep[f] + 1;
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (dep[u] > dep[v])
    swap(u, v);
  for (int i = 0; i <= 16; i++) {
    if ((dep[v] - dep[u]) >> i & 1)
      v = par[i][v];
  }
  if (u == v)
    return u;
  for (int i = 16; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}

bool cmp_dfn(const int &u, const int &v) {
  return dfn[u] < dfn[v];
}

int stk[maxn], tp;

void build(vector<int> &cru) {
  sort(cru.begin(), cru.end(), cmp_dfn);
  stk[tp = 1] = 1;
  vTree::chi[1].clear();
  for (auto u : cru) {
    vTree::imp[u] = true;
    if (u == 1)
      continue;
    int v = lca(stk[tp], u);
    if (v != stk[tp]) {
      while (dfn[stk[tp - 1]] > dfn[v]) {
        vTree::chi[stk[tp - 1]].push_back(stk[tp]);
        --tp;
      }
      if (v == stk[tp - 1]) {
        vTree::chi[v].push_back(stk[tp]);
        tp--;
      } else {
        vTree::chi[v].clear();
        vTree::chi[v].push_back(stk[tp]);
        stk[tp] = v;
      }
    }
    vTree::chi[u].clear();
    stk[++tp] = u;
  }
  for (int i = 1; i < tp; i++)
    vTree::chi[stk[i]].push_back(stk[i + 1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= 16; i++) {
    for (int u = 1; u <= n; u++) {
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    vector<int> cru;
    while (k--) {
      int u;
      scanf("%d", &u);
      cru.push_back(u);
    }
    build(cru);
    if (!vTree::check(1))
      puts("-1");
    else {
      vTree::dp(1);
      printf("%lld\n", vTree::f[1][1]);
    }
    for (auto u : cru) {
      vTree::imp[u] = false;
    }
  }
  cerr << "did not RE" << endl;
  return 0;
}