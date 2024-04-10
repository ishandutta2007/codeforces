#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 998244353;
int dp[1 + nmax][4];
std::vector<std::pair<int,int>> g[1 + nmax];
std::vector<int> colors[1 + nmax];
int edge[1 + nmax][2];

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}
int inverse(int number) {
  return lgpow(number, modulo - 2);
}

void dfs(int node, int parent, int val) {
  int base = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      dfs(to, node, g[node][h].second);
      base = 1LL * base * (dp[to][0] + dp[to][2]) % modulo;
    }
  }

  for(int h = 0; h < colors[node].size(); h++) {
    int where = 0;
    int target = colors[node][h];
    if(target < val)
      where = 0;
    else if(target == val)
      where = 1;
    else 
      where = 2;
    
    int result = 1;

    if(target < modulo) {
      int to = edge[target][0] + edge[target][1] - node;
      if(target == val) {
        result = base;
      } else {
        result =1LL * base * inverse(dp[to][0] + dp[to][2]) % modulo * dp[to][2] % modulo;
        base = 1LL * base * inverse(dp[to][0] + dp[to][2]) % modulo * (dp[to][0] + dp[to][1]) % modulo;
      }
    } else {
      result = base;
    }
    dp[node][where] += result;
    if(modulo <= dp[node][where])
      dp[node][where] -= modulo;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
    colors[x].push_back(i);
    colors[y].push_back(i);
    edge[i][0] = x;
    edge[i][1] = y;
  }
  for(int i = 1;i <= n; i++)
    colors[i].push_back(modulo);
  dfs(1, 0, 0);
  
  std::cout << (0LL + dp[1][0] + dp[1][1] + dp[1][2]) % modulo;
  return 0;
}