#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2505;
vector<int> G[N];
int dp[N][N][3][3], cyc_root[N], sz[N], ndp[N][3][3];
bool vis[N];
// 1: root of subtree
// 2: number of vertices labeled 1
// 3: label of root
// 4: label of bottom vertex of cycle leading out of subtree
//  (if no bottom vtx, all dp values are equal)
// value: maximum number of vertices labeled 2

void chmax(int& x, int y) {
  x = max(x, y);
}

void dfs(int v, int p) {
  bool found_back_edge = 0;
  vis[v] = 1;
  sz[v] = 0;

  for (int n = 1; n < N; n++) {
    for (int r = 0; r < 3; r++) {
      for (int z = 0; z < 3; z++) {
        dp[v][n][r][z] = -INF;
      }
    }
  }

  for (int u: G[v]) {
    if (u == p) continue;
    if (cyc_root[u] == v) continue;
    if (vis[u]) {
      found_back_edge = 1;
      cyc_root[v] = u;
      continue;
    }

    dfs(u, v);
    if (cyc_root[u] != 0 && cyc_root[u] != v) {
      cyc_root[v] = cyc_root[u];
    }

    for (int n1 = 0; n1 <= sz[v]+sz[u]; n1++) {
      for (int r1 = 0; r1 < 3; r1++) {
        for (int z1 = 0; z1 < 3; z1++) {
          ndp[n1][r1][z1] = -INF;
        }
      }
    }

    for (int n1 = 0; n1 <= sz[v]; n1++) {
      for (int r1 = 0; r1 < 3; r1++) {
        for (int z1 = 0; z1 < 3; z1++) {
          for (int n2 = 0; n2 <= sz[u]; n2++) {
            for (int r2 = 0; r2 < 3; r2++) {
              if (r1+r2 == 3) continue;
              for (int z2 = 0; z2 < 3; z2++) {
                if (cyc_root[u] == v && r1+z2 == 3) continue;
                int new_z = z1;
                if (found_back_edge) {
                  new_z = r1;
                }
                if (cyc_root[u] != 0 && cyc_root[v] == cyc_root[u]) {
                  new_z = z2;
                }
                chmax(ndp[n1+n2][r1][new_z], dp[v][n1][r1][z1]+dp[u][n2][r2][z2]);
              }
            }
          }
        }
      }
    }

    for (int n1 = 0; n1 <= sz[v]+sz[u]; n1++) {
      for (int r1 = 0; r1 < 3; r1++) {
        for (int z1 = 0; z1 < 3; z1++) {
          dp[v][n1][r1][z1] = ndp[n1][r1][z1];
        }
      }
    }
    sz[v] += sz[u];
  }

  for (int n = sz[v]; n >= 0; n--) {
    for (int r = 1; r < 3; r++) {
      for (int z = 0; z < 3; z++) {
        if (r == 1) {
          dp[v][n+1][r][z] = dp[v][n][r][z];
          dp[v][n][r][z] = -INF;
        }
        else if (r == 2) dp[v][n][r][z]++;
      }
    }
  }
  sz[v]++;
  if (found_back_edge) {
    for (int n = 0; n <= sz[v]; n++) {
      for (int r = 0; r < 3; r++) {
        for (int z = 0; z < 3; z++) {
          if (r == z) continue;
          dp[v][n][r][z] = -INF;
        }
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = 0; i <= n; i++) {
    int ans = 0;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        chmax(ans, dp[1][i][j][k]);
      }
    }
    cout << ans << " \n"[i==n];
  }
}