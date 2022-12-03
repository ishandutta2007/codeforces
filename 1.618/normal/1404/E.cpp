/*


Q.E.D.
*/
/*
BULB: 1h 
result of thinking: Pure.
#
"".
 
start coding: 08:30
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

#define maxV 40005
#define maxn 205
const int inf = 0x3f3f3f3f;
int n, m;
char s[maxn][maxn];

struct Edge {
  int to, cap, rev;
};
vector<Edge> adj[maxV];
int lev[maxV], iter[maxV];

void addEdge(int u, int v, int c) {
  adj[u].push_back((Edge){v, c, int(adj[v].size())});
  adj[v].push_back((Edge){u, 0, int(adj[u].size()) - 1});
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
      if (e.cap && lev[e.to] > lev[u] + 1) {
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
      int b = dfs(e.to, t, min(e.cap, f - res));
      res += b;
      e.cap -= b;
      adj[e.to][e.rev].cap += b;
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

int main() {
  scanf("%d%d", &n, &m);
  int S = n * m + 1, T = n * m + 2;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.')
        continue;
      int u = (i - 1) * m + j;
      
      if (i == 1 || s[i - 1][j] == '.')
        addEdge(S, u, 1);
      else
        addEdge(u - m, u, 1);
        
      if (i == n || s[i + 1][j] == '.')
        addEdge(S, u, 1);
      else 
        addEdge(u + m, u, 1);
      
      if (j == 1 || s[i][j - 1] == '.')
        addEdge(u, T, 1);
      else
        addEdge(u, u - 1, 1);
      
      if (j == m || s[i][j + 1] == '.')
        addEdge(u, T, 1);
      else
        addEdge(u, u + 1, 1);
    }
  }
  printf("%d\n", dinic(S, T) / 2);
  return 0;
}