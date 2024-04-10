#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const lgmax = 20;
int const inf = 1000000000;

std::vector<std::pair<int,int>> g[1 + nmax];
int monastery[1 + nmax], level[1 + nmax], far[1 + lgmax][1 + nmax];
std::pair<int,int> dp[1 + nmax];

std::pair<int,int> join(std::pair<int,int> f1, std::pair<int,int> f2, int id) {
  if(f1.first == f2.first)
    return {f1.first, id};
  else
    return std::max(f1, f2);
}

void dfs(int node, int parent) {
  far[0][node] = parent;
  level[node] = level[parent] + 1;
  if(monastery[node] == 1) {
    dp[node] = {0, node};
  } else 
    dp[node] = {-inf, node};

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      dfs(to, node);
      std::pair<int, int> sol = dp[to];
      sol.first += g[node][h].second;
      dp[node] = join(sol, dp[node], node);
    }
  }
}
std::pair<int,int> dp2[1 + nmax];

void dfs2(int node, int parent) {
  std::vector<std::pair<int,int>> pref(g[node].size()), suff(g[node].size());
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to == parent)
      pref[h] = suff[h] = {-inf, 0};
    else {
      pref[h] = suff[h] = dp[to];
      pref[h].first += g[node][h].second;
      suff[h].first += g[node][h].second;
    }
  }
  for(int h = 1; h < g[node].size(); h++)
    pref[h] = join(pref[h - 1], pref[h], node);
  for(int h = g[node].size() - 2; 0 <= h; h--)
    suff[h] = join(suff[h + 1], suff[h], node);

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      dp2[to] = dp2[node];
      if(0 < h)
        dp2[to] = join(dp2[to], pref[h - 1], node);
      if(h + 1 < g[node].size())
        dp2[to] = join(dp2[to], suff[h + 1], node);
      dp2[to].first += g[node][h].second;
    }
  }

  pref.clear();
  suff.clear();
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent)
      dfs2(to, node);
  }
}

int getlca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax - 1; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax - 1; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}
int acc[1 + nmax];

void refresh(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      refresh(to, node);
      acc[node] += acc[to];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 1;i <= m; i++) {
    int val;
    std::cin >> val;
    monastery[val] = 1;
  }

  for(int i = 1;i < n; i++) {
    int x, y, val;
    std::cin >> x >> y >> val;
    g[x].push_back({y, val});
    g[y].push_back({x, val});
  }
  dfs(1, 0);
  for(int h = 1; h < lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
  if(monastery[1] == 1) {
    dp2[1] = {0, 1};
  } else 
    dp2[1] = {-inf, 1};
  dfs2(1, 0);

  for(int i = 1;i <= n; i++) {
    if(monastery[i] == 1) {
      dp[i] = join(dp[i], dp2[i], i);
      acc[i]++;
      acc[dp[i].second]++;
      int lca = getlca(i, dp[i].second);
      acc[lca]--;
      acc[far[0][lca]]--;
    }
  }
  refresh(1, 0);
  int result = 0, result2 = 0;
  for(int i = 1;i <= n; i++)
    if(monastery[i] == 0) {
      if(result < acc[i]) {
        result = acc[i];
        result2 = 1;
      } else if(result == acc[i])
        result2++;
    }
  std::cout << result << " " << result2 << '\n';
  return 0;
}