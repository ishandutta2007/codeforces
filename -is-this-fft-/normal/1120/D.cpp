#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 5;
const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
ll cost [MAX_N];
ll dp [MAX_N][3]; // 0 - covers all-but-one, 1 - covers all excl, 2 - covers all incl
ll best [MAX_N];
ll score [MAX_N];
int mulb [MAX_N];

void calc_dp (int u, int p) {
  ll chs = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);
      chs += min(dp[nxt][1], dp[nxt][2]);
      best[u] = min(best[u], score[nxt]);
    }
  }

  int cb = 0;
  for (int nxt : adj[u]) {
    if (score[nxt] == best[u]) {
      cb++;
    }
  }
  if (cb > 1) mulb[u] = 1;

  dp[u][0] = chs + best[u];
  dp[u][1] = chs;
  dp[u][2] = chs + best[u] + cost[u];
  if (u != 1 && adj[u].size() == 1) {
    dp[u][1] = INF;
  }

  score[u] = dp[u][0] - min(dp[u][1], dp[u][2]);
}

void reconstruct (int u, int p, int type, vector<int> &ans) {
  if (type & 1 << 2) {
    ans.push_back(u);
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      int regt = 0;
      if (dp[nxt][1] <= dp[nxt][2]) regt |= 1 << 1;
      if (dp[nxt][2] <= dp[nxt][1]) regt |= 1 << 2;
      
      int nt = 0;
      if (type & 1 << 0) {
        if (score[nxt] == best[u]) {
          nt |= 1 << 0;
          if (mulb[u]) {
            nt |= regt;
          }
        } else {
          nt |= regt;
        }
      }
      if (type & 1 << 1) {
        nt |= regt;
      }
      if (type & 1 << 2) {
        if (score[nxt] == best[u]) {
          nt |= 1 << 0;
          if (mulb[u] || best[u] == 0) {
            nt |= regt;
          }
        } else {
          nt |= regt;
        }
      }

      reconstruct(nxt, u, nt, ans);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calc_dp(1, 0);
  ll ans = min(dp[1][1], dp[1][2]);

  vector<int> ansv;
  int rt = 0;
  if (dp[1][1] <= dp[1][2]) rt |= 1 << 1;
  if (dp[1][2] <= dp[1][1]) rt |= 1 << 2;
  reconstruct(1, 0, rt, ansv);
  sort(ansv.begin(), ansv.end());
  
  cout << ans << " " << (int) ansv.size() << '\n';
  for (int v : ansv) {
    cout << v << " ";
  }
  cout << '\n';
}