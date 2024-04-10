#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int K = 19;
vector<int> G[N];
int par[N][K], depth[N];
long long a[N], b[N];

void dfs(int v) {
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  for (int u: G[v]) {
    depth[u] = depth[v]+1;
    a[u] += a[v];
    b[u] += b[v];
    dfs(u);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      cin >> par[i][0] >> a[i] >> b[i];
      G[par[i][0]].push_back(i);
    }
    dfs(1);
    for (int v = 2; v <= n; v++) {
      if (b[v] <= a[v]) {
        cout << depth[v] << ' ';
        continue;
      }
      int x = v;
      for (int i = K-1; i >= 0; i--) {
        if (b[par[x][i]] > a[v]) {
          x = par[x][i];
        }
      }
      cout << depth[x]-1 << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}