#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> G[N];
int ans[N], st[N], par[N], target[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    function<void(int, int)> dfs = [&] (int v, int p) {
      int children = (int)G[v].size() - (v != p);
      ans[v] = st[v] - target[v] * children;
      for (int u: G[v]) {
        if (u != p) {
          st[u] = target[v];
          target[u] = st[1] - st[u];
          dfs(u, v);
        }
      }
    };
    st[1] = 0;
    target[1] = 1;
    while (1) {
      dfs(1, 1);
      bool win = 1;
      for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
          st[1]++;
          win = 0;
          break;
        }
      }
      if (win) break;
    }

    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
      G[i].clear();
    }
    cout << '\n';
  }
}