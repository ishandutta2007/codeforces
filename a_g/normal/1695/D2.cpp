#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
vector<int> G[N];
bool vis[N];
bool done[N];

// 1
// (2) (3) 6
//        (8) (9)
//
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
    int leaves = 0;
    vector<int> que;
    for (int i = 1; i <= n; i++) {
      if (G[i].size() == 1) {
        leaves++;
        que.push_back(i);
      }
    }
    for (int i = 0; i < (int)que.size(); i++) {
      int v = que[i];
      vis[v] = 1;
      done[v] = 1;
      for (int u: G[v]) {
        if (vis[u]) continue;
        if (G[u].size() == 2) {
          que.push_back(u);
        }
      }
    }

    int ans = leaves;
    for (int i = 1; i <= n; i++) {
      int d = G[i].size();
      if (d >= 3) {
        int done_nbrs = 0;
        for (int u: G[i]) {
          if (done[u]) done_nbrs++;
        }
        if (done_nbrs >= 1) ans--;
      }
    }
    if (accumulate(done+1, done+n+1, 0) == n) ans = 1;
    cout << ans << '\n';

    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      done[i] = 0;
      G[i].clear();
    }
  }
}