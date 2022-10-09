#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>

using ll = long long;

int const nmax = 30000;
int const kmax = 200;
int const modulo =  1000000007;
int const modulo2 = 1000000009;

int dist[1 + kmax][1 + nmax], id[1 + kmax];
int dist2[1 + kmax][1 + nmax];

int seen[1 + nmax];

std::set<std::pair<int,int>> edges;
std::vector<int> g[1 + nmax];

std::map<std::pair<int,int>, int> mp;
int path[1 + nmax];

void dfs(int node, int parent, int ptr) {
  dist2[ptr][node] = dist2[ptr][parent] + 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(0 == dist2[ptr][to]) {
      dfs(to, node, ptr);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= k; i++) {
    for(int j = 1; j <= n; j++) {
      std::cin >> dist[i][j];
      if(dist[i][j] == 0) {
        if(0 < id[i]) {
          std::cout << -1 << '\n';
          return 0;
        }
        id[i] = j;
      }
    }
  }
  //std::cout << "Phase 1\n";
  seen[id[1]] = 1;
  for(int i = 2; i <= k; i++) {
    for(int j = 1; j <= n; j++)
      if(dist[1][id[i]] == dist[1][j] + dist[i][j]) {
        path[dist[1][j]] = j;
      }
    for(int j = 1;j <= dist[1][id[i]]; j++) {
      int x = path[j - 1], y = path[j];
      if(seen[y] == 0) {
        seen[y] = 1;
        edges.insert({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
        if(n <= edges.size()) {
          std::cout << -1 << '\n';
          return 0;
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    int result = 0, result2 = 0;
    for(int j = 1; j <= k; j++) {
      result = (1LL * result * n + dist[j][i]) % modulo;
      result2 = (1LL * result2 * n + dist[j][i]) % modulo2;
    }
    mp[{result, result2}] = i;
  }
  //std::cout << "Phase 2\n";

  for(int i = 1;i <= n; i++)
    if(seen[i] == 0) {
      int result = 0, result2 = 0;
      for(int j = 1; j <= k; j++) {
        result = (1LL * result * n + dist[j][i] - 1) % modulo;
        result2 = (1LL * result2 * n + dist[j][i] - 1) % modulo2;
      }
      if(mp[{result, result2}] == 0) {
        std::cout << -1 << '\n';
        return 0;
      }
      int father = mp[{result, result2}];
      int x = father, y = i;
      if(y < x)
        std::swap(x, y);
      if(edges.find({x, y}) == edges.end()) {
        edges.insert({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
        if(n <= edges.size()) {
          std::cout << -1 << '\n';
          return 0;
        }
      }
    }
  if(edges.size() != n - 1) {
    std::cout << -1 << '\n';
    return 0;
  }

  for(int i = 1; i <= k; i++)
    dfs(id[i], 0, i);
  for(int i = 1;i <= k; i++) {
    for(int j = 1; j <= n; j++) {
      if(dist[i][j] != (dist2[i][j] - 1)) {
        std::cout << -1 << '\n';
        return 0;
      }
    }
  }

  for(std::set<std::pair<int,int>>::iterator it = edges.begin(); it != edges.end(); it ++) {
    std::cout << it->first << " " << it->second << '\n';
  }
  return 0;
}