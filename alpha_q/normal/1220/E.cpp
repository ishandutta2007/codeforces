#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

bitset <N> vis;
ll w[N], dp[N];
vector <int> g[N], tr[N];
int n, m, s, back[N], tot[N], par[N];

void go (int u, int from = -1) {
  vis[u] = 1, tot[u] = 0, par[u] = from;
  for (int v : g[u]) {
    if (v == from) continue;
    if (vis[v]) {
      back[u] = 1;
    } else {
      go(v, u);
      tr[u].emplace_back(v);
      tot[u] += tot[v] + back[v];
    }
  }
}

ll dfs (int u) {
  if (dp[u] != -1) return dp[u]; 
  dp[u] = 0;
  for (int v : tr[u]) {
    dp[u] = max(dp[u], w[v] + dfs(v));
  }
  return dp[u];
}

int main() {
  cin >> n >> m;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", w + i);
    sum += w[i];
  }
  // cout << sum << endl;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  cin >> s; go(s);
  ll ans = 0;
  vector <ll> yo;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    // cout << i << " " << tot[i] << " " << back[i] << endl;
    if (tot[i]) ans += w[i];
    else {
      ll add = dfs(i);
      if (back[i]) ans += w[i];
      else add += w[i];
      yo.emplace_back(add);
    }
  }
  // cout << ans << endl;
  if (!yo.empty()) ans += *max_element(yo.begin(), yo.end());
  cout << ans << '\n';
  return 0;
}