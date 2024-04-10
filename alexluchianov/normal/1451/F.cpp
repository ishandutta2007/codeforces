#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[1 + nmax][1 + nmax];

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> dp(1 + n + m);
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      std::cin >> v[i][j];
      dp[i + j - 1] ^= v[i][j];
    }
  for(int i = 1;i <= n + m; i++)
    if(0 < dp[i]) {
      std::cout << "Ashish\n";
      return ;
    }
  std::cout << "Jeel\n";
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  
  return 0;
}