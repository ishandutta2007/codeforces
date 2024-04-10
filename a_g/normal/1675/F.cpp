#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
bool b[N];
int d[N];
vector<int> G[N];

void dfs(int v, int p) {
  d[v] = d[p]+1;
  for (int u: G[v]) {
    if (u != p) {
      dfs(u, v);
      b[v] |= b[u];
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      b[a] = 1;
    }
    b[y] = 1;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    d[x] = 1;
    dfs(x, x);
    cout << 2*accumulate(b+1, b+n+1, 0) - d[y] << '\n';
    fill(G+1, G+n+1, vector<int>());
    fill(b+1, b+n+1, 0);
  }
}