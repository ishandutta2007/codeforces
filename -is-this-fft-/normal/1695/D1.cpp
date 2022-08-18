#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5; // todo subtask

vector<int> adj [MAX_N];

int dp [MAX_N];

void calc_dp (int u, int p) {
  dp[u] = 0;
  int nz = 0;
  for (int v : adj[u]) {
    if (v == p)
      continue;

    calc_dp(v, u);
    dp[u] += dp[v];
    if (dp[v] == 0)
      nz++;
  }

  dp[u] += max(0, nz - 1);
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (n == 1) {
    cout << 0 << '\n';
    return;
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    calc_dp(i, 0);
    ans = min(ans, 1 + dp[i]);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}