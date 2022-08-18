#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;
const ll INF = 1LL << 60;
  
vector<pair<int, ll>> adj [MAX_N];

namespace mn {
  ll dp [MAX_N][2];

  void dfs (int u, int p, ll pc) {
    dp[u][0] = INF;
    dp[u][1] = 0;

    for (auto nxt : adj[u]) {
      if (nxt.first != p) {
        dfs(nxt.first, u, nxt.second);

        int n = nxt.first;
        ll nd0 = min(dp[u][0] + dp[n][0], dp[u][1] + dp[n][1]);
        ll nd1 = min(dp[u][1] + dp[n][0], dp[u][0] + dp[n][1]);

        dp[u][0] = nd0;
        dp[u][1] = nd1;
      }
    }

    dp[u][1] += pc;
  }
}

namespace mx {
  ll sz [MAX_N];
  ll ans;
  
  void dfs (int u, int p, ll pc, ll N) {
    sz[u] = 1;
    for (auto nxt : adj[u]) {
      if (nxt.first != p) {
        dfs(nxt.first, u, nxt.second, N);
        sz[u] += sz[nxt.first];
      }
    }

    ans += pc * min(sz[u], N - sz[u]);
  }
}

void solve () {
  int vertexc;
  cin >> vertexc;

  vertexc *= 2;
  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  mn::dfs(1, 1, 0);
  mx::dfs(1, 1, 0, vertexc);
  cout << mn::dp[1][0] << " " << mx::ans << '\n';
  
  for (int i = 1; i <= vertexc; i++) {
    adj[i].clear();
    mn::dp[i][0] = 0;
    mn::dp[i][1] = 0;
    mx::sz[i] = 0;
    mx::ans = 0;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}