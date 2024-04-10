/*
start thinking:
BULB:
result of thinking: Lost.

MST=
kruskal
O(m^1.5)?
: 

start coding:
AC:

MSTMST.
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
#define maxm 200005

int n, m, par1[maxn], par2[maxn];
vector<int> lis2[maxn];
// lis1 12
set<int> lis1[maxn];

set<P> es;
struct Edge {
  int u, v, w, id;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
} el[maxm];
vector<P> adj2[maxn];

int fin2(int u) { return par2[u] ? (par2[u] = fin2(par2[u])) : u; }

int fin1(int u) { return par1[u] ? (par1[u] = fin1(par1[u])) : u; }

void uni2(int u, int v, int w) {
  u = fin2(u), v = fin2(v);
  if (u == v)
    return;
  adj2[u].push_back({v, w});
  adj2[v].push_back({u, w});
  if (lis2[u].size() < lis2[v].size())
    par2[u] = v;
  else
    par2[v] = u;
}

void uni1(int u, int v, int w) {
  u = fin1(u), v = fin1(v);
  if (u == v)
    return;
  vector<int> foo, bar;
  for (auto i : lis1[u])
    foo.push_back(i);
  for (auto i : lis1[v])
    bar.push_back(i);
  for (auto i : foo) {
    for (auto j : bar) {
      bool ok = false;
      for (auto ii : lis2[i]) {
        for (auto jj : lis2[j]) {
          if (!es.count({ii, jj})) {
            ok = true;
            break;
          }
        }
        if (ok)
          break;
      }
      if (ok)
        uni2(i, j, w);
    }
  }
  for (auto i : foo) {
    if (fin2(i) != i) {
      lis1[u].erase(i);
      for (auto j : lis2[i])
        lis2[fin2(i)].push_back(j);
    }
  }
  for (auto i : bar) {
    if (fin2(i) != i) {
      lis1[v].erase(i);
      for (auto j : lis2[i])
        lis2[fin2(i)].push_back(j);
    }
  }
  if (lis1[u].size() > lis1[v].size())
    swap(u, v);
  par1[u] = v;
  for (auto i : lis1[u])
    lis1[v].insert(i);
}

int w[18][maxn], par[18][maxn], dep[maxn], ans[maxm];

void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  par[0][u] = f;
  for (auto e : adj2[u]) {
    if (e.first == f)
      continue;
    w[0][e.first] = e.second;
    dfs(e.first, u);
  }
}

int query(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  int ans = 0;
  for (int i = 0; i <= 17; i++) {
    if ((dep[u] - dep[v]) >> i & 1)
      chmax(ans, w[i][u]), u = par[i][u];
  }
  if (u == v)
    return ans;
  for (int i = 17; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      chmax(ans, w[i][u]), chmax(ans, w[i][v]),
      u = par[i][u], v = par[i][v];
    }
  }
  chmax(ans, w[0][u]), chmax(ans, w[0][v]);
  return ans;
}

void solve() {
  scanf("%d%d", &n, &m);
  es.clear();
  for (int i = 1; i <= n; i++) {
    par1[i] = par2[i] = 0;
    adj2[i].clear();
    lis2[i] = {i};
    lis1[i].clear();
    lis1[i].insert(i);
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    el[i] = {u, v, w, i};
    es.insert({u, v});
    es.insert({v, u});
  }
  sort(el + 1, el + m + 1);
  for (int i = 1; i <= m; i++)
    uni1(el[i].u, el[i].v, el[i].w);
  dfs(1, 0);
  for (int i = 1; i <= 17; i++) {
    for (int u = 1; u <= n; u++) {
      par[i][u] = par[i - 1][par[i - 1][u]];
      w[i][u] = max(w[i - 1][u], w[i - 1][par[i - 1][u]]);
    }
  }
  for (int i = 1; i <= m; i++) {
    ans[el[i].id] = query(el[i].u, el[i].v);
  }
  for (int i = 1; i <= m; i++)
    printf("%d%c", ans[i], " \n"[i == m]);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}