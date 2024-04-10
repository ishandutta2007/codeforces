#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500010;

vector <int> g[N];
ll W[N], dp[N][2];
int t, n, k, U[N], V[N];

void go (int u = 1, int from = -1) {
  vector <ll> vec; ll tot = 0;
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e]; 
    if (v == from) continue; ll w = W[e];
    go(v, u); tot += dp[v][0];
    vec.emplace_back(w + dp[v][1] - dp[v][0]);
  }
  sort(vec.begin(), vec.end(), greater <ll> ());
  dp[u][0] = dp[u][1] = tot;
  for (int it = 0; it < 2; ++it) {
    ll cur = tot;
    for (int i = 0; i < min(k - it, (int) vec.size()); ++i) {
      cur += vec[i]; dp[u][it] = max(dp[u][it], cur);
    }
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      scanf("%d %d %lld", U + i, V + i, W + i);
      g[U[i]].emplace_back(i);
      g[V[i]].emplace_back(i);
    }
    go();
    printf("%lld\n", dp[1][0]);
  }
  return 0;
}