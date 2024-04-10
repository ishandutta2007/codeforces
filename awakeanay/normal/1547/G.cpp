#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>

#define int long long

using namespace std;

// NOTE: Code from SCC taken from https://cp-algorithms.com/graph/strongly-connected-components.html
// START OF COPIED CODE
vector<vector<int> > adj, adj_rev;
vector<bool> used;
vector<int> order, component;
vector<std::set<int> > adj_scc;

void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u])
      dfs1(u);

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v])
    if (!used[u])
      dfs2(u);
}
// END OF COPIED CODE

std::vector<int> dp, loop;

int solve(int u) {
  if(dp[u] != -5)
    return dp[u];

  int cur = 0;
  for(int j : adj_scc[u]) {
    int next = solve(j);
    if(next == -1) {
      cur = -1;
      break;
    }
    cur += next;
  }
  
  if(cur > 0 && loop[u])
    cur = -1;
  if(cur > 1)
    cur = 2;

  dp[u] = cur;
  return cur;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    adj = adj_rev = std::vector<std::vector<int> >(n);

    loop = std::vector<int>(n, 0);
    order.clear();
    for(int i = 0; i < m; i++) {
      int a, b;
      std::cin >> a >> b;
      a--; b--;
      if(a == b)
        loop[a] = 1;
      else {
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
      }
    }

    // NOTE: Code from SCC taken from https://cp-algorithms.com/graph/strongly-connected-components.html
    // START OF COPIED CODE
    used.assign(n, false);

    for (int i = 0; i < n; i++)
      if (!used[i])
        dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    adj_scc = std::vector<std::set<int> >(n);

    for (auto v : order)
      if (!used[v]) {
        dfs2(v);

        int root = component.front();
        if(component.size() > 1)
          loop[root] = 1;
        for (auto u : component) roots[u] = root;
        root_nodes.push_back(root);

        component.clear();
      }


    for (int v = 0; v < n; v++) {
      for (auto u : adj[v]) {
        int root_v = roots[v],
        root_u = roots[u];

        if (root_u != root_v)
          adj_scc[root_u].insert(root_v);
      }
    }
    //END OF COPIED CODE
    
    dp = std::vector<int>(n, -5);
    dp[roots[0]] = 1;
    if(loop[roots[0]])
      dp[roots[0]] = -1;
    for(int i = 0; i < n; i++) {
      std::cout << solve(roots[i]) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}