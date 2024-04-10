#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 100000;
char v[5 + nmax];
ll dp[5 + nmax][3][3][3];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  dp[0][0][0][0] = 1;
  v[0] = '#';
  for(int i = 1;i <= n; i++) {
    for(int h1 = 0; h1 <= 2; h1++)
      for(int h2 = 0; h2 <= 2; h2++)
        for(int h3 = 0; h3 <= 2; h3++)
          if(0 < dp[i - 1][h1][h2][h3]) {
            for(char ch = 'a'; ch <= 'a' + m - 1; ch++) {
              int g1 = std::min(2, std::min(h1 + (ch != v[i - 1]), 1 + h2));
              int g2 = std::min(g1, std::min(2, std::min(std::min(h1, h2) + (ch != v[i]), h3 + 1)));
              int g3 = std::min(g2, std::min(2, std::min(h1, std::min(h2, h3)) + (ch != v[i + 1])));
              dp[i][g1][g2][g3] += dp[i - 1][h1][h2][h3];
            }
          }
  }

  ll result = 0;
  for(int i = 0; i <= 2; i++)
    for(int j = 0; j <= 2; j++)
      result += dp[n][i][1][j];
  std::cout << result << '\n';
  return 0;
}