#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

int dp [MAX_N];
int nz [MAX_N];

void calc_dp (int u, int p) {
  dp[u] = 0;
  nz[u] = 0;
  for (int v : adj[u]) {
    if (v == p)
      continue;

    calc_dp(v, u);
    dp[u] += dp[v];
    if (dp[v] == 0)
      nz[u]++;
  }

  dp[u] += max(0, nz[u] - 1);
}

void move (int u, int v) {
  // calc dp[u] as if v was its parent
  dp[u] -= dp[v];
  dp[u] -= max(0, nz[u] - 1);
  if (dp[v] == 0)
    nz[u]--;
  dp[u] += max(0, nz[u] - 1);

  // calc dp[v] as if u was its child
  dp[v] -= max(0, nz[v] - 1);
  if (dp[u] == 0)
    nz[v]++;
  dp[v] += dp[u];
  dp[v] += max(0, nz[v] - 1);
}

void dfs (int u, int p, int &ans) {
  ans = min(ans, 1 + dp[u]);
  for (int nxt : adj[u]) {
    if (nxt == p)
      continue;

    move(u, nxt);
    dfs(nxt, u, ans);
    move(nxt, u);
  }
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

  calc_dp(1, 0);
  int ans = n;
  dfs(1, 0, ans);

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