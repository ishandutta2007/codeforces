#include <bits/stdc++.h>
using namespace std;

const int N = 202;
const int INF = 1e9;
int d[N][N], vis[N];
bool parity[N];
vector<int> G[N];

void dfs(int v, bool p) {
  if (vis[v]) {
    if (parity[v] != p) {
      cout << "NO\n";
      exit(0);
    }
    return;
  }
  vis[v] = 1;
  parity[v] = p;
  for (int u: G[v]) {
    dfs(u, p^1);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }

  while (m--) {
    int u, v, b;
    cin >> u >> v >> b;
    G[u].push_back(v);
    G[v].push_back(u);
    if (b) {
      d[u][v] = 1;
      d[v][u] = -1;
    }
    else {
      d[u][v] = 1;
      d[v][u] = 1;
    }
  }
  dfs(1, 0);

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  int mx = 0;
  int low = 0;
  for (int i = 1; i <= n; i++) {
    int a = *min_element(d[i]+1, d[i]+n+1);
    int b = *max_element(d[i]+1, d[i]+n+1);
    if (d[i][i] < 0) {
      cout << "NO\n";
      return 0;
    }
    if (a < 0) continue;
    if (b > mx) {
      mx = b;
      low = i;
    }
  }

  cout << "YES\n";
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    cout << d[low][i] << " \n"[i==n];
  }
}