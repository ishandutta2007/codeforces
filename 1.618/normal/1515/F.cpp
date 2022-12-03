/*
start thinking:
BULB:
result of thinking:
.
 
start coding:
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

#define maxn 300005
#define mp make_pair
typedef pair<int, int> P;
typedef pair<ll, int> Pli;
int n, m;
ll x, a[maxn];
vector<P> adj[maxn]; // (to, id). 

set<Pli> S;
int par[maxn], rep[maxn];
void ini(int n) {
  for (int i = 1; i <= n; i++) {
    rep[i] = par[i] = i;
    S.insert(mp(a[i], i));
  }
}
int fin(int u) {
  if (par[u] == u)
    return u;
  return par[u] = fin(par[u]);
}
bool uni(int u, int v, int eid) {
  u = fin(u), v = fin(v);
  if (u == v)
    return false;
  printf("%d\n", eid);
  par[u] = v;
  S.erase(mp(a[u], u));
  S.erase(mp(a[v], v));
  a[v] = a[u] + a[v] - x;
  a[u] = 0;
  S.insert(mp(a[v], v));
  if (adj[rep[u]].size() < adj[rep[v]].size()) {
    for (auto i : adj[rep[u]]) {
      adj[rep[v]].push_back(i);
    }
  } else {
    for (auto i : adj[rep[v]]) {
      adj[rep[u]].push_back(i);
    }
    rep[v] = rep[u];
  }
  return true;
}

int main() {
  scanf("%d%d%lld", &n, &m, &x);
  for (int i = 1; i <= n; i++)
    scanf("%lld", a + i);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(mp(v, i));
    adj[v].push_back(mp(u, i));
  }
  ll suma = 0;
  for (int i = 1; i <= n; i++) {
    suma += a[i];
  }
  if (suma < (n - 1) * x) {
    puts("NO");
    return 0;
  }
  puts("YES");
  ini(n);
  for (int i = 1; i < n; i++) {
    auto it = S.end();
    it--;
    int u = it->second;
    while (!uni(u, adj[rep[u]].back().first, adj[rep[u]].back().second))
      adj[rep[u]].pop_back();
  }
  return 0;
}