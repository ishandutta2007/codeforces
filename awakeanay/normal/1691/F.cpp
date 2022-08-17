#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000'000'007;
const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int sub[MAXN];
int fact[MAXN];
int par[MAXN];
std::vector<int> ne[MAXN];
int n, k;

void dfs(int u, int p) {
  sub[u] = 1;
  par[u] = p;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
    sub[u] += sub[j];
    ne[u].push_back(sub[j]);
  }
  if(p != -1)
    ne[u].push_back(n-sub[u]);
}

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

int choose(int n, int k) {
  if(n < k || k < 0 || n < 0)
    return 0;
  int ans = fact[n]*inv(fact[k]);
  ans %= MOD;
  ans *= inv(fact[n-k]);
  ans %= MOD;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  std::cin >> n >> k;

  int ans = 0;
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);

  for(int i = 0; i < n; i++) {
    int add_now = choose(n, k);

    int sum = 0;
    for(int j : ne[i]) {
      sum += choose(j, k);
      sum %= MOD;
    }

    add_now = (add_now - sum + MOD)%MOD;
    add_now = (add_now*n)%MOD;
    ans = (ans + add_now)%MOD;

    for(int j : Adj[i]) {
      int cur = (par[j] == i ? sub[j] : n-sub[i]);
      int ncur = (sum - choose(cur, k) + MOD)%MOD;
      int add = choose(n-cur, k) - ncur + MOD;
      add %= MOD;
      add = (add*cur)%MOD;
      add = (add*(n-cur))%MOD;
      ans = (ans + add)%MOD;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}