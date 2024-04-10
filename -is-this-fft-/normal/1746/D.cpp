#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll score [MAX_N];
ll dp [MAX_N][2];

int par [MAX_N];
vector<int> adj [MAX_N];

ll vals [MAX_N][2];
void build_vals (int u) {
  for (int nxt : adj[u]) {
    vals[nxt][0] = vals[u][0] / (int) adj[u].size();
    vals[nxt][1] = (vals[u][1] + (int) adj[u].size() - 1) / (int) adj[u].size();
    build_vals(nxt);
  }
}

ll get_dp (int u, ll va) {
  if (va == vals[u][0]) return dp[u][0];
  return dp[u][1];
}

void calc_dp (int u) {
  for (int nxt : adj[u]) {
    calc_dp(nxt);
  }

  for (int k = 0; k < 2; k++) {
    if (adj[u].empty()) {
      dp[u][k] = score[u] * vals[u][k];
      continue;
    }
    
    // calculate dp[u][k]
    ll sma = vals[u][k] / (int) adj[u].size();
    ll bi = sma + 1;
    ll bic = vals[u][k] % (int) adj[u].size();

    vector<ll> difs;
    dp[u][k] = 0;
    for (int nxt : adj[u]) {
      ll sdp = get_dp(nxt, sma);
      ll bdp = get_dp(nxt, bi);
      
      dp[u][k] += sdp;
      difs.push_back(bdp - sdp);
    }

    sort(difs.rbegin(), difs.rend());
    for (int i = 0; i < bic; i++) {
      dp[u][k] += difs[i];
    }

    dp[u][k] += score[u] * vals[u][k];
  }
}

void solve () {
  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> score[i];
  }

  vals[1][0] = K;
  vals[1][1] = K;
  build_vals(1);
  calc_dp(1);
  cout << dp[1][0] << '\n';
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