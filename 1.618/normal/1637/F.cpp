/*
start thinking:
BULB:
result of thinking: Pure.

ue[u] = maxh, u,
f[v] := max(0, h[v] - max_{a in subtree(v) && a != v}h[a])
ans[u] = maxh + sum_{v in V}f[v].
u.

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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, h[maxn], par[maxn], maxhIn[maxn], maxhOut[maxn], 
    fIn[maxn], fOut[maxn], fRoot[maxn];
ll ans[maxn];
vector<int> adj[maxn];

void dfsIn(int u, int f) {
  par[u] = f;
  maxhIn[u] = h[u];
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfsIn(v, u);
    chmax(maxhIn[u], maxhIn[v]);
  }
}

void dfsOut(int u, int f) {
  int foo = max(maxhOut[u], h[u]);
  for (auto v : adj[u]) {
    if (v != f) {
      chmax(maxhOut[v], foo);
      chmax(foo, maxhIn[v]);
    }
  }
  foo = max(maxhOut[u], h[u]);
  for (int i = adj[u].size() - 1; i >= 0; i--) {
    int v = adj[u][i];
    if (v != f) {
      chmax(maxhOut[v], foo);
      chmax(foo, maxhIn[v]);
    }
  }
  for (auto v : adj[u]) {
    if (v != f)
      dfsOut(v, u);
  }
}

void dfsAns(int u, int f) {
  for (auto v : adj[u]) {
    if (v != f) {
      ans[v] = ans[u] - fIn[v] + fOut[v];
      dfsAns(v, u);
    }
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfsIn(1, 0);
  dfsOut(1, 0);
  for (int u = 1; u <= n; u++) {
    int foo = maxhOut[u];
    for (auto v : adj[u]) {
      if (v != par[u]) {
        chmax(fIn[u], maxhIn[v]);
        chmax(fRoot[u], maxhIn[v]);
        chmax(fOut[v], foo);
        chmax(foo, maxhIn[v]);
      } else {
        chmax(fRoot[u], maxhOut[u]);
      }
    }
    fIn[u] = max(0, h[u] - fIn[u]);
    fRoot[u] = max(0, h[u] - fRoot[u]);
    foo = maxhOut[u];
    for (int i = adj[u].size() - 1; i >= 0; i--) {
      int v = adj[u][i];
      if (v != par[u]) {
        chmax(fOut[v], foo);
        fOut[v] = max(0, h[u] - fOut[v]);
        chmax(foo, maxhIn[v]);
      }
    }
  }
  for (int i = 2; i <= n; i++)
    ans[1] += fIn[i];
  dfsAns(1, 0);
  ll res = infll;
  for (int i = 1; i <= n; i++)
    chmin(res, ans[i] + fRoot[i]);
  printf("%lld\n", res + maxhIn[1]);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}