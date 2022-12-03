/*
result of thinking: Lost.

a1<a2<...<an
ai|aji->jGG()3
...3 2:
=.
: G.
 [NOI2015] G...
: .

start coding: 23:30
AC: 23:56
*/
#include <bits/stdc++.h>
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

#define maxn 50005
#define maxV 200005
int n, a[maxn];
struct Edge {
  int to, cap, rev;
};
vector<Edge> adj[maxV];
int lev[maxV], iter[maxV];

void addEdge(int u, int v, int c) {
  adj[u].push_back((Edge){v, c, int(adj[v].size())});
  adj[v].push_back((Edge){u, 0, int(adj[u].size() - 1)});
}

void bfs(int s) {
  for (int i = 0; i <= 4 * n + 1; i++)
    lev[i] = inf;
  lev[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto e : adj[u]) {
      if (e.cap && lev[e.to] == inf) {
        lev[e.to] = lev[u] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int u, int t, int f) {
  if (u == t)
    return f;
  int b = 0;
  for (int& i = iter[u]; i < (int)adj[u].size(); i++) {
    auto& e = adj[u][i];
    if (e.cap && lev[u] < lev[e.to]) {
      int foo = dfs(e.to, t, min(f - b, e.cap));
      b += foo;
      e.cap -= foo;
      adj[e.to][e.rev].cap += foo;
      if (b == f)
        return b;
    }
  }
  return b;
}

int dinic(int s, int t) {
  int res = 0;
  while (true) {
    bfs(s);
    if (lev[t] == inf)
      return res;
    for (int i = 0; i <= 4 * n + 1; i++)
      iter[i] = 0;
    res += dfs(s, t, inf);
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  for (int i = 0; i <= n * 4 + 1; i++)
    adj[i].clear();
  for (int i = 1; i <= n * 2; i++) {
    addEdge(0, i, 1);
    addEdge(i + n * 2, n * 4 + 1, 1);
  }
  for (int i = 1; i <= n; i++) {
    addEdge(i + n, i + n * 2, 1);
    for (int j = 1; j < i; j++) {
      if (a[i] % a[j] == 0) {
        addEdge(i, j + n * 2, 1);
        addEdge(i + n, j + n * 3, 1);
        addEdge(i + n, j + n * 2, 1);
      }
    }
  }
  printf("%d\n", dinic(0, n * 4 + 1) - n);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();  
  return 0;
}