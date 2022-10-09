#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 4000;
int v[1 + nmax];

int seen[1 + nmax];

int dp[1 + nmax], last[1 + nmax];

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> vec;
  for(int i = 1; i <= 2 * n; i++)
    std::cin >> v[i];
  vec.push_back({1, 1});
  for(int i = 2; i <= 2 * n; i++)
    if(v[vec.back().first] < v[i])
      vec.push_back({i, 1});
    else
      vec.back().second++;
  for(int i = 1;i <= 2 * n; i++)
    dp[i] = last[i] = seen[i] = 0;
  dp[0] = 1;
  for(int i = 0; i < vec.size(); i++) 
    for(int j = 2 * n; vec[i].second <= j; j--)
      if(1 == dp[j - vec[i].second]) {
        dp[j] = 1;
      }
  if(dp[n] == 0)
    std::cout << "NO\n";
  else 
    std::cout << "YES\n";
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}