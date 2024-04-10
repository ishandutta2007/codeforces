#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 300000;
int const modulo = 998244353;
int sol[5 + nmax];
std::vector<int> g[5 + nmax];

int dfs(int node, int parent, int k, bool &verdict) {
  int acc = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(parent != to) {
      acc += dfs(to, node, k, verdict);
    }
  }

  if(acc % k == 0)
    return 1;
  else if((acc + 1) % k == 0) {
    return 0;
  } else {
    verdict = false;
    return 1;
  }
}

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    g[i].clear();

  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; i++)
    sol[i] = 0;
  
  sol[1] = 1;
  
  for(int i = 1;i <= n - 1; i++) {
    sol[1] = 1LL * sol[1] * 2 % modulo;
  }

  for(int i = 2; i < n; i++) {
    bool verdict = true;
    if((n - 1) % i == 0) {
      if(1 == dfs(1, 0, i, verdict)) {
        sol[i] = verdict;
      }
    }
  }

  for(int i = n; 1 <= i; i--)
    for(int j = i * 2; j <= n; j += i) {
      sol[i] -= sol[j];
      if(sol[i] < 0)
        sol[i] += modulo;
    }

  for(int i = 1; i <= n; i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) 
    solve();
  return 0;
}