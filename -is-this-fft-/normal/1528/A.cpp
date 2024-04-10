#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
ll val [MAX_N][2];
ll dp [MAX_N][2];

void calc_dp (int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = 0;
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);

      for (int i = 0; i < 2; i++) {
        ll mx = 0;
        for (int j = 0; j < 2; j++) {
          mx = max(mx, abs(val[u][i] - val[nxt][j]) + dp[nxt][j]);
        }
        dp[u][i] += mx;
      }
    }
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 1; i <= n; i++) {
    cin >> val[i][0] >> val[i][1];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calc_dp(1, 0);

  cout << max(dp[1][0], dp[1][1]) << '\n';
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