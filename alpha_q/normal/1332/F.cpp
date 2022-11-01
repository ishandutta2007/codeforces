#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300010;
const int MOD = 998244353;

int n;
ll dp[N][2][2];
vector <int> g[N];

void go (int u = 1, int par = -1) {
  for (int v : g[u]) if (v ^ par) go(v, u);
  for (int ed = 0; ed < 2; ++ed) {
    for (int pr = 0; pr < 2; ++pr) {
      if (!ed) {
        ll all = 1, edge = 1, noEdge = 1;
        for (int v : g[u]) if (v ^ par) {
          noEdge = noEdge * dp[v][0][1] % MOD;
          edge = edge * (dp[v][0][1] + dp[v][1][1]) % MOD;
          all = all * (dp[v][0][0] + dp[v][1][0]) % MOD;
        }
        dp[u][ed][pr] = (all + edge - noEdge + MOD) % MOD;
      } else {
        ll cur = 1;
        for (int v : g[u]) if (v ^ par) {
          cur = cur * (dp[v][0][0] + dp[v][1][0]) % MOD;
        }
        dp[u][ed][pr] = cur;
        if (!pr) {
          ll extra = 1;
          for (int v : g[u]) if (v ^ par) {
            extra = extra * (dp[v][0][1] + dp[v][1][1]) % MOD;
          }
          dp[u][ed][pr] = (dp[u][ed][pr] + extra) % MOD;
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go(); cout << (dp[1][0][0] + MOD - 1) % MOD << '\n';
  return 0;
}