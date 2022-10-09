#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <map>

using ll = long long;

int const nmax = 2000000;
int const inf = 1000000001;

int a[1 + nmax], b[1 + nmax], ptr = 0;
int a2[1 + nmax], b2[1 + nmax];
std::map<int,int> mp;

void normalize(int n) {
  for(int i = 1; i <= n; i++) {
    if(mp[a[i]] == 0) 
      mp[a[i]] = ++ptr;
    if(mp[b[i]] == 0) 
      mp[b[i]] = ++ptr;
    a2[i] = mp[a[i]];
    b2[i] = mp[b[i]];
  }
}

std::vector<int> g[1 + nmax];
int seen[1 + nmax];

int dfs(int node) {
  int result = -2 + g[node].size();
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0)
      result += dfs(to);
  }
  return result;
}

bool solve(int n, int target) {
  for(int i = 1;i <= ptr; i++) {
    g[i].clear();
    seen[i] = 0;
  }
  for(int i = 1;i <= n ;i++) {
    int x = a2[i];
    int y = b2[i];
    if(a[i] <= target && b[i] <= target) {
      g[x].push_back(y);
      g[y].push_back(x);
    } else if(a[i] <= target) {
      g[x].push_back(x);
      g[x].push_back(x);
    } else if(b[i] <= target) {
      g[y].push_back(y);
      g[y].push_back(y);
    } else
      return false;
  }

  for(int i = 1;i <= ptr; i++) 
    if(seen[i] == 0) 
      if(0 < dfs(i))
        return false;
  return true;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<int> aux;
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    aux.push_back(a[i]);
    aux.push_back(b[i]);
  }
  normalize(n);
  aux.push_back(0);
  aux.push_back(inf);
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());

  int x = 0;
  if(solve(n, inf) == 0) {
    std::cout << -1 << '\n';
    return 0;
  }
  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(x + jump < aux.size() && solve(n, aux[x + jump]) == 0)
      x += jump;
  std::cout << aux[x + 1] << '\n';
  return 0;
}