/*
result of thinking: Pure.
SCCSCC""
. 

start coding: 17:20 
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
#define mp make_pair
typedef pair<int, int> P;

int n, m, q;
vector<P> adj[maxn];

int low[maxn], dfn[maxn], ind, stk[maxn], k;
bool ins[maxn], scc[maxn];
bool vis[maxn];
ll res, f[maxn], d[maxn];

void dfs(int u) {
  vis[u] = true;
  for (auto e : adj[u]) {
    int v = e.first;
    if (!scc[v])
      continue;
    if (!vis[v]) {
      f[v] = f[u] + e.second;
      dfs(v);
    } else {
      res = __gcd(res, abs(f[u] + e.second - f[v]));
    }
  }
}

void tarjan(int u) {
  low[u] = dfn[u] = ++ind;
  stk[++k] = u;
  ins[u] = true;
  for (auto e : adj[u]) {
    int v = e.first;
    if (!dfn[v]) {
      tarjan(v);
      chmin(low[u], low[v]);
    } else if (ins[v]) {
      chmin(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    
//    cout << "new scc: " << u << endl;
//    system("pause");
    
    vector<int> lis;
    int tp;
    do {
      tp = stk[k--];
      ins[tp] = false;
      lis.push_back(tp);
    } while (tp != u);
    for (auto v : lis)
      scc[v] = true;
    res = 0;
    dfs(u);
    for (auto v : lis) {
      
//      cout << v << " ";
      
      d[v] = res;
      vis[v] = scc[v] = false;
    }
    
//    cout << endl;
//    system("pause");
    
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back(mp(v, w));
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i])
      tarjan(i);
  }
  scanf("%d", &q);
  while (q--) {
    int v;
    ll r, mod;
    scanf("%d%lld%lld", &v, &r, &mod);
    puts(r % __gcd(d[v], mod) == 0 ? "YES" : "NO");
  }
  return 0;
}