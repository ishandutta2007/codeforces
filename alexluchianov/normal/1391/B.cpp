#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
char v[1 + nmax][1 + nmax];

int solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      std::cin >> v[i][j];
  int result = 0;
  for(int i = 1;i < m; i++)
    result += (v[n][i] == 'D');
  for(int i = 1;i < n; i++)
    result += (v[i][m] == 'R');
  return result;
}
int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) 
    std::cout << solve() << '\n';

  return 0;
}