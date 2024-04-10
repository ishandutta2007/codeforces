#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 100005;

int n;
std::vector<int> Adj[MAXN];
std::vector<std::pair<int, int> > ans;
std::vector<std::pair<int, int> > best[MAXN];
int par[MAXN];
std::pair<int, int> end[MAXN];
std::vector<std::pair<int, int> > el;
int dp[MAXN][2];
int rec[MAXN][2];

void dfs1(int u, int p) {
  int deg = 0;
  int sum = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs1(j, u);
    deg++;
    sum += dp[j][0];
    best[u].push_back({dp[j][1]-dp[j][0], j});
  }
  std::sort(best[u].begin(), best[u].end());
  std::reverse(best[u].begin(), best[u].end());

  dp[u][0] = dp[u][1] = sum;
  rec[u][0] = rec[u][1] = 0;
  for(int j = 0; j < 2; j++) {
    int tmax = 2-j;
    int csum = 0;
    for(int i = 0; i < best[u].size(); i++) {
      csum += best[u][i].first+1;
      if(i < tmax && sum + csum > dp[u][j]) {
        rec[u][j] = i+1;
        dp[u][j] = sum + csum;
      }
    }
  }
}

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  par[u] += par[v];
  par[v] = u;
  end[u].second = end[v].second;
}

void dfs2(int u, int j, int p) {
  for(int i = 0; i < best[u].size(); i++) {
    if(i < rec[u][j]) {
      int x = u;
      int y = best[u][i].second;
      
      int a, b;
      if(end[root(x)].first == x+1)
        a = end[root(x)].second;
      else
        a = end[root(x)].first;
      if(end[root(y)].first == y+1)
        b = end[root(y)].second;
      else
        b = end[root(y)].first;

      merge(u, best[u][i].second);
      end[root(u)] = {a, b};
      dfs2(best[u][i].second, 1, u);
    }
    else
      dfs2(best[u][i].second, 0, u);
  }
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;
    ans.clear();

    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      best[i].clear();
    }
    el.clear();
    for(int i = 0; i < n; i++) {
      par[i] = -1;
      end[i] = {i+1, i+1};
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
      el.push_back({u, v});
    }

    dfs1(0, -1);
    dfs2(0, 0, -1);

    for(std::pair<int, int> j : el) {
      int u = j.first;
      int v = j.second;
      if(root(u) == root(v))
        continue;
      
      ans.push_back({u+1, v+1});
      ans.push_back({end[root(u)].second, end[root(v)].first});
      merge(u, v);
    }

    std::cout << ans.size()/2 << std::endl;
    for(int i = 0; i < ans.size(); i++) {
      std::cout << ans[i].first << " " << ans[i].second << " ";
      if(i%2)
        std::cout << std::endl;
    }
  }

  return 0;
}