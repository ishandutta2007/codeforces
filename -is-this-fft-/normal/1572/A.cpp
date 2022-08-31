#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int vis [MAX_N];
int dp [MAX_N];
vector<int> deps [MAX_N];

void dfs (int u, bool &ok) {
  vis[u] = 1;

  for (int prv : deps[u]) {
    if (!vis[prv]) {
      dfs(prv, ok);
    } else if (vis[prv] == 1) {
      ok = false;
    }

    dp[u] = max(dp[u], dp[prv] + (int) (prv > u));
  }

  vis[u] = 2;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    vis[i] = 0;
    
    int k;
    cin >> k;

    deps[i] = vector<int> (k);
    for (int j = 0; j < k; j++) {
      cin >> deps[i][j];
    }
  }

  bool ok = true;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, ok);
      ans = max(ans, dp[i]);
    }
  }

  if (!ok) {
    cout << -1 << '\n';
  } else {
    cout << 1 + ans << '\n';
  }
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