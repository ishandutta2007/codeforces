/*
start thinking:
BULB:
result of thinking: Pure.

, .

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, m, V;
vector<int> adj1[maxn], adj2[maxn];

namespace Planar {
  set<int> vis[maxn];
  vector<int> face[maxn];
  map<P, int> id;

  void dfs(int u, int v, vector<int> &lis) {
    vis[u].insert(v);
    lis.push_back(v);
    auto it = upper_bound(adj1[v].begin(), adj1[v].end(), u);
    if (it == adj1[v].end())
      it = adj1[v].begin();
    if (!vis[v].count(*it))
      dfs(v, *it, lis);
  }

  void work() {
    for (int i = 1; i <= n; i++)
      sort(adj1[i].begin(), adj1[i].end());
    for (int i = 1; i <= n; i++) {
      for (auto j : adj1[i]) {
        if (!vis[i].count(j)) {
          dfs(i, j, face[++V]);
          sort(face[V].begin(), face[V].end(), greater<int>());
        }
      }
    }
    sort(face + 1, face + V + 1);
    for (int i = 1; i <= V; i++) {
      for (int j = 0; j < (int)face[i].size(); j++) {
        int x = face[i][j], y = face[i][(j + 1) % face[i].size()];
        if (x > y)
          swap(x, y);
        if (id.count({x, y})) {
          adj2[i].push_back(id[{x, y}]);
          adj2[id[{x, y}]].push_back(i);
        } else {
          id[{x, y}] = i;
        }
      }
    }
  }
}

int siz[maxn], maxsiz[maxn], tot, cen, ans[maxn];
bool vis[maxn];

void finCen(int u, int f) {
  siz[u] = 1;
  maxsiz[u] = 0;
  for (auto v : adj2[u]) {
    if (vis[v] || v == f)
      continue;
    finCen(v, u);
    siz[u] += siz[v];
    chmax(maxsiz[u], siz[v]);
  }
  chmax(maxsiz[u], tot - siz[u]);
  if (!cen || maxsiz[cen] > maxsiz[u])
    cen = u;
}

void calcSiz(int u, int f) {
  siz[u] = 1;
  for (auto v : adj2[u]) {
    if (vis[v] || v == f)
      continue;
    calcSiz(v, u);
    siz[u] += siz[v];
  }
}

void solve(int u, int d) {
  ans[u] = d;
  calcSiz(u, 0);
  vis[u] = true;
  for (auto v : adj2[u]) {
    if (vis[v])
      continue;
    tot = siz[v], cen = 0;
    finCen(v, 0);
    solve(cen, d + 1);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    adj1[i % n + 1].push_back(i);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj1[a].push_back(b);
    adj1[b].push_back(a);
  }
  Planar::work();
  tot = V, cen = 0;
  finCen(1, 0);
  solve(cen, 1);
  for (int i = 1; i <= V; i++)
    printf("%d%c", ans[i], " \n"[i == V]);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}