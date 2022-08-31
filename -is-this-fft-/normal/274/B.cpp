#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
ll arr [MAX_N];
pair<ll, ll> dp [MAX_N]; // neg, pos

void dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);

      dp[u].first = max(dp[u].first, dp[nxt].first);
      dp[u].second = max(dp[u].second, dp[nxt].second);
    }
  }

  arr[u] -= dp[u].first;
  arr[u] += dp[u].second;
  if (arr[u] < 0) {
    dp[u].second += -arr[u];
  } else {
    dp[u].first += arr[u];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  dfs(1, 0);

  cout << dp[1].first + dp[1].second << endl;
}