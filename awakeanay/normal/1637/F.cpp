#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;
const int INF = 1'000'000'000'000'000'00;

std::pair<int, int> dp[MAXN];
int h[MAXN];
std::vector<int> Adj[MAXN];
int par[MAXN];
std::pair<int, int> dp2[MAXN];

std::pair<int, int> merge(const std::pair<int, int> &u, const std::pair<int, int> &v) {
  std::pair<int, int> ret;
  ret.first = u.first + v.first;
  ret.second = std::max(u.second, v.second);
  return ret;
}

std::pair<int, int> add(int u, const std::pair<int, int> &v) {
  std::pair<int, int> ret = v;
  if(u > ret.second) {
    ret.first += u-ret.second;
    ret.second = u;
  }
  return ret;
}

void dfs(int u, int p) {
  par[u] = p;

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    
    dfs(j, u);

    dp[u] = merge(dp[u], dp[j]);
  }

  dp[u] = add(h[u], dp[u]);
}

void dfs2(int u, int p, std::pair<int, int> px) {
  int k = Adj[u].size();
  k -= p != -1;
  dp2[u] = px;

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dp2[u] = merge(dp2[u], dp[j]);
  }

  dp2[u] = add(h[u], dp2[u]);

  std::pair<int, int> pref[k];
  int val[k];

  std::pair<int, int> spec = add(h[u], px);

  int ct = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;

    val[ct++] = j;
  }

  std::pair<int, int> cur = {0, 0};
  for(int j = 0; j < k; j++) {
    pref[j] = cur = merge(cur, dp[val[j]]);
  }
  cur = {0, 0};
  for(int j = k-1; j >= 0; j--) {
    std::pair<int, int> next = cur;
    if(j) {
      next = merge(pref[j-1], next);
    }
    next = merge(next, px);
    next = add(h[u], next);

    dfs2(val[j], u, next);

    cur = merge(cur, dp[val[j]]);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int max = 0;
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::cin >> h[i];
    max = std::max(max, h[i]);
  }

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);
  dfs2(0, -1, {0, 0});

  int ans = INF;
  for(int i = 0; i < n; i++) {
    int cur = max + dp2[i].first;
    ans = std::min(ans, cur);
  }

  std::cout << ans << std::endl;

  return 0;
}