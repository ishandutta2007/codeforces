#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 998244353;
std::string s;
std::vector<std::pair<int,int>> g[1 + 2 * nmax];
int seen[1 + 2 * nmax], dist[1 + 2 * nmax];

void add_edge(int x, int y, int cost) {
  g[x].push_back({y, cost});
  g[y].push_back({x, cost});
}

void dfs(int node, int color, int &verdict) {
  if(dist[node] == -1) {
    dist[node] = color;
    seen[node] = 1;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first, cost = g[node][h].second;
      dfs(to, color ^ cost, verdict);
    }
  } else if(dist[node] != color)
    verdict = 0;
}

int eval(int n, int start) {
  for(int i = 0; i < 2 * n; i++) {
    g[i].clear();
    dist[i] = seen[i] = -1;
  }
  for(int i = 0; i < n / 2; i++)
    add_edge(i, n - 1 - i, 0);
  
  for(int i = start; i < n ; i++) 
    if(i < n - 1 - (i - start))
      add_edge(n + i, n + n - 1 - (i - start), 0);
  
  for(int i = start; i < n; i++)
    if(s[i] != '?')
      add_edge(i, n + i, s[i] - '0');

  int result = 1;

  for(int i = 0; i < start; i++)
    if(s[i] != '?')
      dfs(i, s[i] - '0', result);
  dfs(n + start, 1, result);

  for(int i = 0; i < 2 * n; i++)
    if(dist[i] == -1 && (i < n || n + start <= i)) {
      dfs(i, 0, result);
      result = 1LL * result * 2 % modulo;
    }
  return result;
}

int main() {
  std::cin >> s;
  int n = s.size();
  int result = 0;
  for(int i = 1; i < n; i++) {
    result += eval(n, i);
    if(modulo <= result)
      result -= modulo;
  }
  
  std::cout << result;
  return 0;
}