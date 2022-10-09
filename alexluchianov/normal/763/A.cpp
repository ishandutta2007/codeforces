#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 100000;
int v[5 + nmax], far[5 + nmax];
std::vector<int> g[5 + nmax];

int join(int gala, int galb) {
  if(gala == galb)
    return gala;
  else
    return 0;
}

int dp[5 + nmax], dp2[5 + nmax];

int dfs(int node, int parent) {
  far[node] = parent;
  for(int h = 0;h < g[node].size(); h++)
    if(g[node][h] == parent)
      g[node].erase(g[node].begin() + h);
  int color = v[node];
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    color = join(color, dfs(to, node));
  }
  dp[node] = color;
  return color;
}

void dfs2(int node, int parent) {
  std::vector<int> pref(g[node].size()), suff(g[node].size());
  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    pref[h] = suff[h] = dp[to];
  }
  for(int h = 1; h < g[node].size();h++)
    pref[h] = join(pref[h - 1], pref[h]);
  for(int h = g[node].size() - 2; 0 <= h; h--)
    suff[h] = join(suff[h + 1], suff[h]);
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    dp2[to] = v[node];
    if(0 < h)
      dp2[to] = join(dp2[to], pref[h - 1]);
    if(h + 1 < g[node].size())
      dp2[to] = join(dp2[to], suff[h + 1]);
    if(0 != parent)
      dp2[to] = join(dp2[to], dp2[node]);
  }
  pref.clear();
  suff.clear();
  for(int h = 0; h < g[node].size(); h++)
    dfs2(g[node][h], node);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  dfs(1, 0);
  dfs2(1, 0);
  for(int i = 1;i <= n; i++) {
    bool valid = true;
    for(int h = 0; h < g[i].size(); h++)
      valid &= (0 < dp[g[i][h]]);
    if(1 < i)
      valid &= (0 < dp2[i]);
    if(valid == true) {
      std::cout << "YES\n";
      std::cout << i << '\n';
      return 0;
    }
  }
  std::cout << "NO\n";
  return 0;
}