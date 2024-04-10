#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int N = 1000010;
const int MOD[] = {1000003, 998244353, 1000000007, 1000000009};

int dx[2][2] = {{0, 1}, {0, -1}};
int dy[2][2] = {{1, 0}, {-1, 0}};

string g[N];
int n, m, tot, d[2][N], from_src[N][K], to_snk[N][K];

inline bool valid (int x, int y) {
  return x >= 0 and y >= 0 and x < n and y < m and g[x][y] == '.';
}

void bfs (int id, int sx, int sy) {
  queue <int> q;
  int src = sx * m + sy;
  for (int i = 0; i < tot; ++i) d[id][i] = -1;
  d[id][src] = 0, q.emplace(src);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int x = u / m, y = u % m;
    for (int i = 0; i < 2; ++i) {
      int nx = x + dx[id][i], ny = y + dy[id][i];
      if (!valid(nx, ny)) continue;
      int v = nx * m + ny;
      if (d[id][v] == -1) d[id][v] = d[id][u] + 1, q.emplace(v);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> n >> m;
  tot = n * m;
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  bfs(0, 0, 0); 
  bfs(1, n - 1, m - 1);
  int src = 0, snk = n * m - 1;
  if (d[0][snk] == -1) {
    cout << "0\n"; return 0;
  }
  if (g[0][1] == '#' or g[1][0] == '#') {
    cout << "1\n"; return 0;
  }
  for (int it = 0; it < K; ++it) {
    to_snk[snk][it] = 1;
  }
  for (int x = n - 1; x >= 0; --x) {
    for (int y = m - 1; y >= 0; --y) {
      int u = x * m + y;
      if (u == snk) continue;
      if (g[x][y] == '#') continue;
      for (int i = 0; i < 2; ++i) {
        int nx = x + dx[0][i], ny = y + dy[0][i];
        if (!valid(nx, ny)) continue;
        int v = nx * m + ny;
        for (int it = 0; it < K; ++it) {
          to_snk[u][it] += to_snk[v][it];
          if (to_snk[u][it] >= MOD[it]) to_snk[u][it] -= MOD[it];
        }
      }
    }
  }
  for (int it = 0; it < K; ++it) {
    from_src[src][it] = 1;
  }
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      int u = x * m + y;
      if (u == src) continue;
      if (g[x][y] == '#') continue;
      for (int i = 0; i < 2; ++i) {
        int nx = x + dx[1][i], ny = y + dy[1][i];
        if (!valid(nx, ny)) continue;
        int v = nx * m + ny;
        for (int it = 0; it < K; ++it) {
          from_src[u][it] += from_src[v][it];
          if (from_src[u][it] >= MOD[it]) from_src[u][it] -= MOD[it];
        }
      }
    }
  }
  // for (int i = 0; i < tot; ++i) cout << from_src[i][0] << " "; cout << endl;
  // for (int i = 0; i < tot; ++i) cout << to_snk[i][0] << " "; cout << endl;
  int yo = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int u = i * m + j, good = 1;
      if (u == src or u == snk or g[i][j] == '#') continue;
      for (int it = 0; it < K; ++it) {
        int cur = (long long) from_src[u][it] * to_snk[u][it] % MOD[it];
        if (cur ^ from_src[snk][it]) {
          good = 0; break;
        } 
      }
      if (good) {
        // cout << i << " " << j << endl;
        yo = 1; break;
      }
    }
    if (yo) break;
  }
  cout << (yo ? "1\n" : "2\n");
  return 0;
}