#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>

#define int long long
std::vector<std::pair<int, int> > Adj[2005];
int d[2005][2005];
bool poss = true;
int count;

void dfs(int u, int p, int cur, int id) {
  count++;
  if(d[u][id] != cur)
    poss = false;
  for(std::pair<int, int> j : Adj[u]) {
    if(j.first == p)
        continue;
    dfs(j.first, u, cur + j.second, id);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) 
      std::cin >> d[i][j];

  std::set<int> edges[n];
  for(int i = 1; i < n; i++) {
    std::vector<std::pair<int, int> > help;
    for(int j = 0; j < n; j++) {
      if(d[i][j] + d[j][0] == d[i][0]) {
        help.push_back({d[j][0], j});
      }
    }
    std::sort(help.begin(), help.end());
    for(int j = 1; j < help.size(); j++) {
      edges[help[j-1].second].insert(help[j].second);
    }
  }

  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += edges[i].size();

  if(sum != n-1) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  for(int i = 0; i < n; i++) {
    for(auto it = edges[i].begin(); it != edges[i].end(); it++) {
      Adj[*it].push_back({i, d[i][*it]});
      Adj[i].push_back({*it, d[i][*it]});
    }
  }
  
  for(int i = 0; i < n; i++) {
    count = 0;
    dfs(i, -1, 0, i);
    if(count != n) {
      poss = false;
      break;
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(d[i][j] != d[j][i])
        poss = false;
      if(i != j && d[i][j] == 0)
        poss = false;
    }

  if(poss && sum == n-1 && count == n)
    std::cout << "YES" << std::endl;
  else 
    std::cout << "NO" << std::endl;
  
  return 0;
}