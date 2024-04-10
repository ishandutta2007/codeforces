#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int const nmax = 1000;
std::vector<int> g[1 + nmax];
int far[1 + nmax], blocked[1 + nmax];
int level[1 + nmax];
int n;

std::vector<int> extract(int target) {
  std::vector<int> aux;
  for(int i = 1;i <= n; i++)
    if(level[i] == target && blocked[i] == 0)
      aux.push_back(i);
  return aux;
}

void dfs(int node, int parent) {
  level[node] = level[parent] + 1;
  far[node] = parent;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

std::pair<int,int> ask(std::vector<int> v) {
  if(v.size() == 0)
    return {nmax * 3, nmax * 3};

  std::cout << "? " << v.size() << " ";
  for(int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
  std::pair<int,int> sol;
  std::cin >> sol.first >> sol.second;
  return sol;
}

int findlevel(int from, int to, int disttarget) {
  from--;
  int result = 0;
  for(int jump = (1 << 10); 0 < jump; jump /= 2) {
    if(from + jump <= to) {
      std::pair<int,int> sol = ask(extract(from + jump));
      if(sol.second == disttarget) {
        from += jump;
        result = sol.first;
      }
    }
  }
  return result;
}

void block_chain(int node) {
  if(node == 0)
    return;
  blocked[node] = 1;
  block_chain(far[node]);
}

void solve() {
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    blocked[i] = 0;
    g[i].clear();
  }

  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  std::vector<int> all;
  for(int i = 1;i <= n; i++)
    all.push_back(i);
  std::pair<int,int> result = ask(all);
  int root = result.first;
  int dist = result.second;
  level[0] = -1;
  dfs(root, 0);

  int node1 = findlevel(dist / 2, dist, dist);
  block_chain(node1);
  if(dist - level[node1] == 0) {
    std::cout << "! " << node1 << " " << root << std::endl;
    std::string response;
    std::cin >> response;
    return ;
  } else {
    int node2 =  ask(extract(dist - level[node1])).first;
    std::cout << "! " << node1 << " " << node2 << std::endl;
    std::string response;
    std::cin >> response;
    return ;
  }
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}