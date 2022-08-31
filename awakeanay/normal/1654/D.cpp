#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;
const int MOD = 998244353;
std::vector<std::pair<int, std::pair<int, int> > > Adj[MAXN];

int pr[MAXN];
int pmax[MAXN];

int sum = 0;
int mult = 1;
int cur = 1;

void divide(int x) {
  for(int i = 2; i*i <= x; i++) {
    if(x%i == 0) {
      int ct = 0;
      while(x%i == 0) {
        ct++;
        x /= i;
      }
      pr[i] += ct;
      pmax[i] = std::max(pmax[i], pr[i]);
    }
  }
  if(x != 1) {
    pr[x]++;
    pmax[x] = std::max(pmax[x], pr[x]);
  }
}

void multiply(int x) {
  for(int i = 2; i*i <= x; i++) {
    if(x%i == 0) {
      int ct = 0;
      while(x%i == 0) {
        ct++;
        x /= i;
      }
      pr[i] -= ct;
    }
  }
  if(x != 1) {
    pr[x]--;
  }
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

void dfs(int u, int p) {
  sum += cur;
  sum %= MOD;

  for(auto j : Adj[u]) {
    if(j.first == p)
      continue;

    cur *= j.second.second;
    cur %= MOD;
    cur *= inv(j.second.first);
    cur %= MOD;

    multiply(j.second.second);
    divide(j.second.first);

    dfs(j.first, u);

    multiply(j.second.first);
    divide(j.second.second);

    cur *= j.second.first;
    cur %= MOD;
    cur *= inv(j.second.second);
    cur %= MOD;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
      Adj[i].clear();
    for(int i = 0; i <= n; i++) {
      pr[i] = 0;
      pmax[i] = 0;
    }

    for(int i = 1; i < n; i++) {
      int u, v, x, y;
      std::cin >> u >> v >> x >> y;
      u--; v--;
      Adj[u].push_back({v, {x, y}});
      Adj[v].push_back({u, {y, x}});
    }

    sum = 0;
    cur = 1;
    mult = 1;
    dfs(0, -1);

    for(int j = 1; j <= n; j++) {
      mult = mult*expo(j, pmax[j]);
      mult %= MOD;
    }

    std::cout << (sum*mult)%MOD << std::endl;
  }

  return 0;
}