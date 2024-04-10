#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 1000000;
int type[1 + nmax];
std::vector<int> g[5 + nmax];
int base[5 + nmax], dp[5 + nmax][2];

void dfs(int node) {
  for(int h = 0; h < g[node].size(); h++)
    dfs(g[node][h]);
  if(type[node] < 2)
    base[node] = type[node];
  else if(type[node] == 2) 
    base[node] = !base[g[node][0]];
  else if(type[node] == 3)
    base[node] = (base[g[node][0]] & base[g[node][1]]);
  else if(type[node] == 4)
    base[node] = (base[g[node][0]] | base[g[node][1]]);
  else if(type[node] == 5)
    base[node] = (base[g[node][0]] ^ base[g[node][1]]);
}

void solve(int node) {
  if(type[node] == 2) {
    int to = g[node][0];
    dp[to][0] = dp[node][1];
    dp[to][1] = dp[node][0];
    solve(to);
  } else if(2 < type[node]) {
    int x, y;
    x = g[node][0];
    y = g[node][1];
    if(type[node] == 3) {
      for(int h = 0; h < 2; h++)
        dp[x][h] = dp[node][h & base[y]];
      for(int h = 0; h < 2; h++)
        dp[y][h] = dp[node][base[x] & h];
    } else if(type[node] == 4) {
      for(int h = 0; h < 2; h++)
        dp[x][h] = dp[node][h | base[y]];
      for(int h = 0; h < 2; h++)
        dp[y][h] = dp[node][base[x] | h];
    } else if(type[node] == 5) {
      for(int h = 0; h < 2; h++)
        dp[x][h] = dp[node][h ^ base[y]];
      for(int h = 0; h < 2; h++)
        dp[y][h] = dp[node][base[x] ^ h];
    }
    solve(x);
    solve(y);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::string op;
    std::cin >> op;
    if(op == "NOT") {
      int x;
      std::cin >> x;
      g[i].push_back(x);
      type[i] = 2;
    } else if(op == "IN") {
      int x;
      std::cin >> x;
      type[i] = x;
    } else {
      int x, y;
      std::cin >> x >> y;
      g[i].push_back(y);
      g[i].push_back(x);
      if(op == "AND")
        type[i] = 3;
      else if(op == "OR")
        type[i] = 4;
      else if(op == "XOR")
        type[i] = 5;
    }
  }
  dfs(1);
  dp[1][0] = 0;
  dp[1][1] = 1;
  solve(1);
  std::string answer;
  for(int i = 1;i <= n; i++) 
    if(type[i] < 2)
      answer += (char)(dp[i][!type[i]] + '0');
  std::cout << answer << '\n';
  return 0;
}