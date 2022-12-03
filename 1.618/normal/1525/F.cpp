/*


Q.E.D.

result of thinking: Lost. 

#"" # #dp 

start coding: 14:40
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

#define maxV 107
const int inf = 0x3f3f3f3f;
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
  memset(lev, 0x3f, sizeof(lev));
  lev[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto e : adj[u]) {
      if (e.cap && lev[u] + 1 < lev[e.to]) {
        lev[e.to] = lev[u] + 1;
        que.push(e.to);
      }
    }
  }
}
int dfs(int u, int t, int f) {
  if (u == t)
    return f;
  int res = 0;
  for (int &i = iter[u]; i < (int)adj[u].size(); i++) {
    Edge &e = adj[u][i];
    if (e.cap && lev[u] < lev[e.to]) {
      int b = dfs(e.to, t, min(f - res, e.cap));
      e.cap -= b;
      adj[e.to][e.rev].cap += b;
      res += b;
      if (res == f)
        return res;
    }
  }
  return res;
}
int dinic(int s, int t) {
  int res = 0;
  while (true) {
    bfs(s);
    if (lev[t] == inf)
      return res;
    memset(iter, 0, sizeof(iter));
    res += dfs(s, t, inf);
  }
}

#define maxn 55
int n, m, k;
bool del[maxV];

int work() {
  bfs(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    if (!del[i] && lev[i] == inf) {
      int mat;
      for (auto &e : adj[i]) {
        if (!e.cap) {
          mat = e.to;
          e.cap = 1;
          adj[e.to][e.rev].cap = 0;
        } else if (e.to == 2 * n + 1) {
          e.cap = 0;
        }
      }
      for (auto &e : adj[mat]) {
        if (e.to == 2 * n + 2) {
          e.cap = 1;
          adj[e.to][e.rev].cap = 0;
        }
      }
      del[i] = true;
      return i;
    }
  }
  for (int i = n + 1; i <= n + n; i++) {
    if (!del[i] && lev[i] != inf) {
      int mat;
      for (auto &e : adj[i]) {
        if (e.cap) {
          mat = e.to;
          e.cap = 0;
          adj[e.to][e.rev].cap = 1;
        } else if (e.to == 2 * n + 2) {
          adj[e.to][e.rev].cap = 0;
        }
      }
      for (auto &e : adj[mat]) {
        if (e.to == 2 * n + 1) {
          e.cap = 0;
          adj[e.to][e.rev].cap = 1;
        }
      }
      del[i] = true;
      return n - i;
    }
  }
}

int fir, b[maxn];
ll x[maxn], y[maxn], f[maxn][maxn];
int cho[maxn][maxn];

void construct(int i, int j) {
  if (i == 1) {
    for (int l = fir; l <= j; l++)
      printf("%d ", b[l]);
  } else {
    construct(i - 1, cho[i][j]);
    for (int l = max(fir, cho[i][j] + 1); l <= j; l++)
      printf("%d ", b[l]);
  }
  printf("0 ");
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v + n, 1);
  }
  for (int i = 1; i <= n; i++) {
    addEdge(2 * n + 1, i, 1);
    addEdge(i + n, 2 * n + 2, 1);
  }
  fir = n - dinic(2 * n + 1, 2 * n + 2);
  for (int i = fir; i < n; i++)
    b[i] = work();
  
  for (int i = 1; i <= k; i++)
    scanf("%lld%lld", x + i, y + i);
  if (k < fir) {
    printf("%d\n", k);
    for (int i = 1; i <= k; i++)
      printf("0%c", i == k ? '\n' : ' ');
    return 0;
  }
  printf("%d\n", k + k - fir + 1);
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= k; i++)
    f[1][i] = max(0ll, x[1] - max(0, i - fir + 1) * y[1]); 
  for (int i = 2; i <= k; i++) {
    for (int j = i; j <= k; j++) {
      for (int l = i - 1; l <= j; l++) {
        if (chmax(f[i][j], f[i - 1][l] + max(0ll, x[i]
                           - max(0, (j - max(fir, l + 1) + 1)) * y[i])))
          cho[i][j] = l;
      }
    }
  }
  construct(k, k);
  puts("");
  return 0;
}