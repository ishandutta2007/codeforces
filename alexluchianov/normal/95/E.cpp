#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const threshold = 300000;
std::vector<int> g[1 + nmax];
int seen[1 + nmax];

int dfs(int node) {
  seen[node] = 1;
  int result = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0)
      result += dfs(to);
  }
  return result;
}

int quick[1 + nmax];

bool isnice(int x) {
  if(x == 0)
    return 1;
  else if(x % 10 == 4 || x % 10 == 7)
    return isnice(x / 10);
  return 0;
}
int _count[1 + nmax];


int dp[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> v, un;

  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      v.push_back(dfs(i));
  
  std::sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
    _count[v[i]]++;

  for(int i = 1; i <= n; i++)
    quick[i] = isnice(i);
  un = v;
  un.erase(std::unique(un.begin(), un.end()), un.end());
  for(int i = 0; i < un.size(); i++) {
    if(quick[un[i]] == 1) {
      std::cout << 0;
      return 0;
    }
  }

  for(int i = 0; i < un.size(); i++)
    for(int j = i; j < un.size(); j++) {
      int x = un[i], y = un[j];
      _count[x]--;
      _count[y]--;
      if(0 <= _count[x] && 0 <= _count[y] && quick[x + y] == 1) {
        std::cout << 1;
        return 0;
      }
      _count[x]++;
      _count[y]++;
    }

  for(int i = 0; i < un.size(); i++)
    for(int j = i; j < un.size(); j++)
      for(int h = j; h < un.size(); h++) {
        int x = un[i], y = un[j], z = un[h];
        _count[x]--;
        _count[y]--;
        _count[z]--;
        if(0 <= _count[x] && 0 <= _count[y] && 0 <= _count[z] && quick[x + y + z] == 1) {
          std::cout << 2;
          return 0;
        }
        _count[x]++;
        _count[y]++;
        _count[z]++;
      }
  
  std::vector<int> q;
  q.push_back(0);
  
  auto start = std::chrono::high_resolution_clock::now();

  for(int i = 0; i < v.size(); i++) {
    int ptr = q.size();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    if(threshold <= duration.count())
      break;
    for(int j = 0; j < ptr; j++) {
      int val = q[j] + v[i];
      if(dp[val] == 0 || dp[q[j]] + 1 < dp[val]) {
        if(dp[val] == 0)
          q.push_back(val);
        dp[val] = dp[q[j]] + 1;
      }
    }
  }
  int smin = n + 1;
  for(int i = 1; i <= n; i++)
    if(quick[i] == 1 && 0 < dp[i])
      smin = std::min(smin, dp[i]);
  if(smin <= n)
    std::cout << smin - 1;
  else
    std::cout << -1;
}