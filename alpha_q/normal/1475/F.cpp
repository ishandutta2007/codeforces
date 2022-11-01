#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

bool bad;
char a[N][N];
vector <int> adj[N];
int t, n, g[N][N], p[N], col[N];

inline int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

inline void unite (int x, int y) {
  x = find(x), y = find(y);
  if (rand() & 1) swap(x, y);
  if (x ^ y) p[x] = y;
}

void dfs (int u, int c = 0) {
  col[u] = c;
  for (int v : adj[u]) {
    if (col[v] == -1) dfs(v, c ^ 1);
    else if (col[v] == c) bad = 1;
  }
}

bool ok() {
  for (int i = 1; i <= n + n; ++i) {
    p[i] = i, col[i] = -1, adj[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (g[i][j] == 0) unite(i, n + j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (g[i][j] == 1) {
        if (find(i) == find(n + j)) return 0;
        adj[find(i)].emplace_back(find(n + j));
        adj[find(n + j)].emplace_back(find(i));
      }
    }
  }
  bad = 0;
  for (int i = 1; i <= n + n; ++i) {
    if (col[i] == -1) dfs(i);
  }
  return !bad;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", a[i] + 1);
      for (int j = 1; j <= n; ++j) {
        g[i][j] = a[i][j] - '0';
      }
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%s", a[i] + 1);
      for (int j = 1; j <= n; ++j) {
        g[i][j] ^= (a[i][j] - '0');
      } 
    }
    puts(ok() ? "YES" : "NO");
  }
  return 0;
}