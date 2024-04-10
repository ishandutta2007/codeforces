#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;

int const nmax = 300000;
ll v[1 + nmax];
int mult[1 + nmax];

int jump(int a) {
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

struct Edge{
  int x;
  int y;
  int id;
};

Edge edges[1 + nmax];
std::vector<std::pair<int,int>> g[1 + nmax]; 
int seen[1 + nmax], grad[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, t;
  std::cin >> n >> m >> t;
  ll sum = 0;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1; i <= n; i++) 
    sum += v[i];
  if(sum < 1LL * t * (n - 1)) {
    std::cout << "NO\n";
    return 0;
  }
  for(int i = 1;i <= n;i++)
    mult[i] = i;

  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if(jump(x) != jump(y)) {
      g[x].push_back({y, i});
      g[y].push_back({x, i});
      mult[jump(y)] = jump(x);

      grad[x]++;
      grad[y]++;

    }
  }

  std::vector<int> leafs;
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  
  std::vector<int> sol;
  for(int i = 1;i <= n; i++)
    if(grad[i] == 1)
      leafs.push_back(i);
  std::cout << "YES\n";

  for(int phase = 1; phase <= n - 1; phase++) {
    int leaf = leafs.back();
    leafs.pop_back();
    seen[leaf] = 1;
    for(int h = 0; h < g[leaf].size(); h++) {
      int to = g[leaf][h].first;
      if(seen[to] == 0) {
        grad[to]--;
        if(grad[to] == 1)
          leafs.push_back(to);
        if(t <= v[leaf] + v[to]) {
          v[to] += v[leaf] - t;
          std::cout << g[leaf][h].second << '\n';
        } else {
          sol.push_back(g[leaf][h].second);
        }
      }
    }
  }

  std::reverse(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << '\n';
  return 0;
}