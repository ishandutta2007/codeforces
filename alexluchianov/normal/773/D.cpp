#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
ll const inf = 1000000000000000000;
ll w[1 + nmax][1 + nmax];
ll dp[1 + nmax];
int seen[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
	std::cin >> n;
	for(int i = 1;i <= n; i++)
	  for(int j = i + 1;j <= n; j++) {
      std::cin >> w[i][j];
			w[j][i] = w[i][j];
	  }
  for(int i = 1;i <= n; i++)
	  dp[i] = inf;
  ll smin = inf;
  for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      smin = std::min(smin, w[i][j]);
  for(int i = 1;i <= n; i++)
    for(int j = i + 1; j <= n; j++) {
      w[i][j] -= smin;
      w[j][i] = w[i][j];
    } 
  for(int i = 1;i <= n; i++) 
    for(int j = 1;j <= n; j++)
      if(i != j)
        dp[i] = std::min(dp[i], w[i][j] * 2);
  
  for(int i = 1;i <= n; i++) {
    int id = 0;
    for(int j = 1;j <= n; j++)
      if(seen[j] == 0 && (id == 0 || dp[j] < dp[id]))
        id = j;
    seen[id] = 1;
    for(int j = 1;j <= n; j++)
      if(seen[j] == 0)
        dp[j] = std::min(dp[j], w[j][id] + dp[id]);
  }
  for(int i = 1; i <= n; i++)
    std::cout << (n - 1) * smin + dp[i] << '\n';
  return 0;
}