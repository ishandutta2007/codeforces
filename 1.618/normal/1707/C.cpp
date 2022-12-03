/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
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
#define maxm 200005
int n, m;
vector<P> sanBian;
vector<int> adj[maxn];

namespace Dsu {
  int par[maxn];
  int fin(int u) {
    return par[u] ? (par[u] = fin(par[u])) : u;
  }
  bool uni(int u, int v) {
    u = fin(u), v = fin(v);
    if (u == v)
      return false;
    par[u] = v;
    return true;
  }
}

int st[maxn], ed[maxn], ind, tag[maxn], dep[maxn], par[17][maxn];

void dfs1(int u, int f) {
  par[0][u] = f;
  dep[u] = dep[f] + 1;
  st[u] = ++ind;
  for (auto v : adj[u]) {
    if (v != f)
      dfs1(v, u);
  }
  ed[u] = ind;
}

int fin(int u, int k) {
  for (int i = 0; i < 17; i++) {
    if (k >> i & 1)
      u = par[i][u];
  }
  return u;
}

void dfs2(int u, int f) {
  tag[u] += tag[f];
  for (auto v : adj[u]) {
    if (v != f)
      dfs2(v, u);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (Dsu::uni(u, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    } else {
      sanBian.emplace_back(u, v);
    }
  }
  dfs1(1, 0);
  for (int i = 1; i <= 16; i++) {
    for (int u = 1; u <= n; u++) {
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
  }
  for (auto i : sanBian) {
    int u = i.first, v = i.second;
    if (st[u] > st[v])
      swap(u, v);
    if (st[v] <= ed[u]) {
      tag[fin(v, dep[v] - dep[u] - 1)]++;
      tag[v]--;
    } else {
      tag[1]++;
      tag[u]--;
      tag[v]--;
    }
  }
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    printf(tag[i] ? "0" : "1");
  puts("");
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}