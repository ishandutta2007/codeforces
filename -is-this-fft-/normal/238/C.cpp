#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e3 + 5;

vector<pair<int, int>> adj [MAX_N]; // <vtx, is inverse>
int dp [MAX_N][3];

void calc_dp (int u, int p, int is_up) {
  int sum0 = 0, mn1 = 0, mn12 = 0;
  for (auto e : adj[u]) {
    int nxt = e.first;
    
    if (nxt != p) {
      calc_dp(nxt, u, e.second);

      sum0 += dp[nxt][0];
      mn1 = min(mn1, dp[nxt][1] - dp[nxt][0]);
      mn12 = min(mn12, min(dp[nxt][1], dp[nxt][2]) - dp[nxt][0]);
    }
  }

  dp[u][0] = sum0 + is_up;
  dp[u][1] = sum0 + mn1 + !is_up;
  dp[u][2] = sum0 + mn12 + is_up;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
  }

  int ans = MAX_N;
  for (int i = 1; i <= n; i++) {
    calc_dp(i, 0, 0);
    ans = min(ans, dp[i][0]);
    ans = min(ans, dp[i][2]);
  }

  cout << ans << endl;
}