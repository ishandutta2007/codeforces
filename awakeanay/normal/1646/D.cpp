#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int deg[MAXN];
int ans[MAXN];
std::pair<int, int> dp[2][MAXN];

void solve(int u, int p) {
  dp[0][u] = {0, -1};
  dp[1][u] = {1, -deg[u]};

  for(int j : Adj[u]) {
    if(j == p)
      continue;

    solve(j, u);

    dp[1][u] = {dp[1][u].first + dp[0][j].first, dp[1][u].second + dp[0][j].second};
    std::pair<int, int> best = std::max(dp[0][j], dp[1][j]);
    dp[0][u] = {dp[0][u].first + best.first, dp[0][u].second + best.second};
  }
}

int ct;
int sum;

void print(int u, int p, int v) {
  ans[u] = v ? deg[u] : 1;
  ct += v;
  sum += ans[u];

  for(int j : Adj[u]) {
    if(j == p)
      continue;

    if(v)
      print(j, u, 0);
    else {
      std::pair<int, int> best = std::max(dp[0][j], dp[1][j]);
      print(j, u, dp[1][j] == best);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  if(n == 2) {
    std::cout << "2 2\n1 1\n";
    return 0;
  }

  for(int i = 1; i < n; i++) { 
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    deg[u]++;
    deg[v]++;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  solve(0, -1);
  int v = dp[0][0] < dp[1][0];
  print(0, -1, v);

  std::cout << ct << " " << sum << std::endl;
  for(int i = 0; i < n; i++)
    std::cout << ans[i] << " ";
  std::cout << std::endl;

  return 0;
}