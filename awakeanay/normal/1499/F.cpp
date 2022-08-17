#include <iostream>
#include <vector>

const int MOD = 998244353;
const int MAXN = 5005;

int n, k;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int cur[MAXN];
int prec[MAXN];

void add(int u) {
  std::vector<long long> next(k+1, 0);

  for(int i = 0; i <= k; i++) {
    next[i] = ((long long)cur[i])*((long long)pre[u][k]);
    next[i] %= MOD;
    if(i == 0) continue;
    next[i] += ((long long) cur[i])*((long long) pre[u][std::min(k-i-1, i-1)]);
    next[i] %= MOD;

    next[i] += ((long long)dp[u][i-1])*((long long)prec[std::min(k-i, i)]);
    next[i] %= MOD;

    if(2*i <= k) {
      next[i] += MOD - (((long long)dp[u][i-1])*((long long)cur[i]))%MOD;
      next[i] %= MOD;
    }
  }

  for(int i = 0; i <= k; i++) {
    cur[i] = prec[i] = next[i];
    if(i) {
      prec[i] += prec[i-1];
      prec[i] %= MOD;
    }
  }
}

std::vector<int> Adj[MAXN];

void dfs(int u, int p) {
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
  }

  for(int i = 0; i <= k; i++) {
    prec[i] = 1;
    cur[i] = (i==0);
  }

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    add(j);
  }

  for(int i = 0; i <= k; i++) {
    dp[u][i] = cur[i];
    pre[u][i] = prec[i];
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> k;

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);

  std::cout << pre[0][k] << std::endl;

  return 0;
}