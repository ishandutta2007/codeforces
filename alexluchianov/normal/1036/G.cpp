#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using ll = long long;

int const nmax = 1000000;
int const sigma = 20;

std::vector<int> g[1 + nmax];
int source[1 + nmax];

std::map<int,int> mp;
int dp[1 + nmax];

void dfs(int node) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(dp[to] == 0)
      dfs(to);
    dp[node] |= dp[to];
  }
  if(g[node].size() == 0)
    dp[node] = (1<<mp[node]);
}

int reach[1 + sigma];
int reach2[1 + sigma];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    source[i] = 1;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    source[y] = 0;
  }
  int ptr = 0;
  for(int i = 1; i <= n; i++)
    if(g[i].size() == 0)
      mp[i] = ptr++;

  int ptr2 = 0;
  for(int i = 1; i <= n; i++)
    if(source[i] == 1) {
      dfs(i);
      reach[ptr2++] = dp[i];
      for(int j = 0; j < ptr; j++)
        if((1 << j) & dp[i])
          reach2[j] |= (1 << (ptr2 - 1));
    }

  for(int mask = 1; mask < (1 << ptr2) - 1; mask++) {
    int mask2 = 0;
    for(int i = 0; i < ptr; i++)
      if((1 << i) & mask)
        mask2 |= reach[i];
    
    bool valid = true;
    /*
    for(int j = 0; j < ptr; j++)
      if((1 << j) & mask2)
        if((reach2[j] & mask) != reach2[j])
          valid = false;
    */

    if(valid == true && __builtin_popcount(mask) == __builtin_popcount(mask2)) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";
  return 0;
}