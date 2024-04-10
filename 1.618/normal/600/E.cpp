/*
O(nlogn), O(n), 1e9+7splay.
: T(u) = sum_{vson(u)}T(v) + (u)
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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, col[maxn], dfn[maxn], siz[maxn], ori[maxn], ind, son[maxn];
vector<int> adj[maxn];
int cnt[maxn], maxcnt;
ll curans, ans[maxn];

void add(int c) {
  cnt[c]++;
  if (cnt[c] > maxcnt) {
    maxcnt = cnt[c];
    curans = c;
  } else if (cnt[c] == maxcnt) {
    curans += c;
  }
}

void dfs1(int u, int f) {
  dfn[u] = ++ind;
  ori[ind] = u;
  siz[u] = 1;
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]])
      son[u] = v;
  }
}

void dfs2(int u, int f, bool keep) {
  for (auto v : adj[u]) {
    if (v != f && v != son[u])
      dfs2(v, u, false);
  }
  if (son[u])
    dfs2(son[u], u, true);
  add(col[u]);
  for (auto v : adj[u]) {
    if (v != f && v != son[u]) {
      for (int i = dfn[v]; i < dfn[v] + siz[v]; i++)
        add(col[ori[i]]);
    }
  }
  ans[u] = curans;
  if (!keep) {
    // .
    for (int i = dfn[u]; i < dfn[u] + siz[u]; i++)
      cnt[col[ori[i]]] = 0;
    maxcnt = curans = 0;
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", col + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, true);
  for (int i = 1; i <= n; i++) {
    printf("%lld%c", ans[i], " \n"[i == n]);
  }
  return 0;
}