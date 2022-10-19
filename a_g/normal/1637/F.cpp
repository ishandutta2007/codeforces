#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int h[N], dp[N];
vector<int> adj[N];

long long dfs(int v, int p) {
  long long ans = 0;
  int highest = 0;
  int second_highest = 0;
  for (int u: adj[v]) {
    if (u != p) {
      ans += dfs(u, v);
      dp[v] = max(dp[u], dp[v]);
      second_highest = max(dp[u], second_highest);
      if (second_highest > highest) swap(highest, second_highest);
    }
  }
  ans += max(dp[v], h[v]) - dp[v];
  dp[v] = max(dp[v], h[v]);
  if (v == p) {
    ans += max(dp[v], h[v])-second_highest;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int H = 0;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    if (h[i] > H) {
      H = h[i];
      root = i;
    }
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << dfs(root, root) << '\n';
}