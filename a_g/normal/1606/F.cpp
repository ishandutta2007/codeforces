#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// source: ButterCake (https://codeforces.com/problemset/submission/1606/134542141)

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> c;

void dfs(int v, int p) {
  int children = 0;
  int dpsize = 0;
  for (int u: adj[v]) {
    if (u != p) {
      dfs(u, v);
      children++;
      dpsize = max({dpsize, (int)dp[u].size(), c[u]});
    }
  }
  dp[v].resize(dpsize, children);
  for (int u: adj[v]) {
    if (u != p) {
      for (int i = 0; i < dp[u].size(); i++) {
        int contrib = max(0, dp[u][i]-i-1);
        if (!contrib) break;
        dp[v][i] += contrib;
      }
      for (int i = dp[u].size(); i < dpsize; i++) {
        int contrib = max(0, c[u]-i-1);
        if (!contrib) break;
        dp[v][i] += contrib;
      }
    }
  }
  while (!dp[v].empty() && dp[v].back() <= children) dp[v].pop_back();
  c[v] = children;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  adj.resize(n);
  c.resize(n);
  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dp.resize(n);
  dfs(0, 0);

  int q;
  cin >> q;
  while (q--) {
    int v, k;
    cin >> v >> k;
    v--;
    if (k >= dp[v].size()) {
      cout << c[v] << '\n';
    }
    else {
      cout << dp[v][k] << '\n';
    }
  }
}