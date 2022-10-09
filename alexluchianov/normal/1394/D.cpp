#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 200000;
ll const inf = 400000000000;
int v[5 + nmax], height[5 + nmax];
std::pair<ll,ll> dp[5 + nmax];
std::vector<int> g[5 + nmax];
std::vector<ll> diffs;

ll solve(std::vector<std::pair<ll,ll>> &aux, int cost) {
  int n = aux.size();
  diffs.resize(n);
  for(int i = 0; i < aux.size(); i++)
    diffs[i] = aux[i].second - aux[i].first;
  std::sort(diffs.begin(), diffs.end());
  ll base = 0;
  for(int i = 0; i < aux.size(); i++)
    base += aux[i].first;
  ll result = base + 1LL * cost * n;
  for(int i = 1; i <= diffs.size(); i++) {
    base += diffs[i - 1];
    result = std::min(result, base + 1LL * cost * std::max(i, (int)aux.size() - i));
  }
  diffs.clear();
  return result;
}
std::vector<std::pair<ll,ll>> aux;

ll dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }

  for(int h = 0; h < g[node].size(); h++) 
    dfs(g[node][h], node);

  if(parent == 0) {
    std::vector<std::pair<ll,ll>> aux;
    for(int h = 0; h < g[node].size(); h++)
      aux.push_back(dp[g[node][h]]);
    return solve(aux, v[node]);
  } else {
    for(int h = 0; h < g[node].size(); h++)
      aux.push_back(dp[g[node][h]]);
    dp[node] = {inf, inf};
    if(height[node] <= height[parent]) {
      aux.push_back({inf, 0});
      dp[node].first = solve(aux, v[node]);
      aux.pop_back();
    }
    if(height[parent] <= height[node]){
      aux.push_back({0, inf});
      dp[node].second = solve(aux, v[node]);
      aux.pop_back();
    }
    aux.clear();
    return 0;
  }
}

int main() {
  std::ios::sync_with_stdio();
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  for(int i = 1; i <= n; i++)
    std::cin >> height[i];
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::cout << dfs(1, 0) << '\n';
  return 0;
}