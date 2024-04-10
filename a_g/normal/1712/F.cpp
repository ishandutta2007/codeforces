#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> f(n, -1), depth(n);
  vector<vector<int>> G(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    depth[i] = depth[p]+1;
    G[p].push_back(i);
    G[i].push_back(p);
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (G[i].size() == 1) {
      que.push_back(i);
      f[i] = 0;
    }
  }
  for (int i = 0; i < (int)que.size(); i++) {
    for (int v: G[que[i]]) {
      if (f[v] == -1) {
        f[v] = f[que[i]]+1;
        que.push_back(v);
      }
    }
  }

  int q;
  cin >> q;
  vector<int> queries(q), ans(q);
  for (int& x: queries) cin >> x;

  vector<vector<int>> dp(n);
  for (int v = n-1; v >= 0; v--) {
    for (int u: G[v]) {
      if (u < v) continue;
      if (dp[u].size() > dp[v].size()) {
        swap(dp[u], dp[v]);
      }
      for (int i = 0; i < (int)dp[u].size(); i++) {
        for (int qn = 0; qn < q; qn++) {
          do {
            int j = max(0, ans[qn]+1-queries[qn]-i);
            if (j < (int)dp[v].size() &&
                dp[v][j]+dp[u][i]-2*depth[v] >= ans[qn]+1) ans[qn]++;
            else break;
          } while (1);
        }
      }
      for (int i = 0; i < (int)dp[u].size(); i++) {
        dp[v][i] = max(dp[v][i], dp[u][i]);
      }
    }
    for (int qn = 0; qn < q; qn++) {
      do {
        int j = max(0, ans[qn]+1-queries[qn]-f[v]);
        if (j < (int)dp[v].size() && dp[v][j]-depth[v] >= ans[qn]+1) ans[qn]++;
        else break;
      } while (1);
    }
    if (f[v] < (int)dp[v].size()) {
      dp[v][f[v]] = max(dp[v][f[v]], depth[v]);
    }
    else {
      assert(f[v] == (int)dp[v].size());
      dp[v].push_back(depth[v]);
    }
  }

  for (int x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
}