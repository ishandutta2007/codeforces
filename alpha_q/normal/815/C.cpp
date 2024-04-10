#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 5005;
const ll INF = 1e16 + 5;

vector <int> g[N];
int n, p[N], sz[N];
ll b, c[N], d[N];
ll f[2][N][N];

void dfs (int u) {
  sz[u] = 1;
  f[0][u][0] = 0;
  f[0][u][1] = c[u];
  f[1][u][1] = d[u];
  for (int v : g[u]) {
    dfs(v);
    for (int i = sz[u]; i >= 0; --i) {
      for (int j = sz[v]; j >= 0; --j) {
        f[0][u][i + j] = min(f[0][u][i + j], f[0][u][i] + f[0][v][j]);
        f[1][u][i + j] = min(f[1][u][i + j], f[1][u][i] + f[0][v][j]);
        f[1][u][i + j] = min(f[1][u][i + j], f[1][u][i] + f[1][v][j]);
      }
    }
    sz[u] += sz[v];
  }
}

int main() {
  scanf("%d %lld", &n, &b);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", c + i, d + i);
    d[i] = c[i] - d[i];
    if (i > 1) {
      scanf("%d", p + i);
      g[p[i]].push_back(i);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n; ++k) {
        f[i][j][k] = INF;
      }
    }
  }
  dfs(1);
  int ans = 0;
  for (int i = n; i; --i) {
    if (min(f[0][1][i], f[1][1][i]) <= b) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}