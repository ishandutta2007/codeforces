#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 50;

char v[5 + nmax][5 + nmax];
int dp[5 + nmax][5 + nmax][5 + nmax][5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int x = 1; x <= n; x++)
    for(int y = 1; y <= n; y++)
      for(int x2 = x; x2 <= n; x2++)
        for(int y2 = y; y2 <= n; y2++)
          dp[x][y][x2][y2] = nmax;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      cin >> v[i][j];
      if(v[i][j] == '.')
        dp[i][j][i][j] = 0;
      else
        dp[i][j][i][j] = 1;
    }

  for(int x = 1; x <= n; x++)
    for(int y = 1; y <= n; y++)
      for(int x2 = x; 1 <= x2; x2--)
        for(int y2 = y; 1 <= y2; y2--) {
          dp[x2][y2][x][y] = min(dp[x2][y2][x][y], max((x - x2 + 1), (y - y2 + 1)));
          for(int i = x2; i < x; i++)
            dp[x2][y2][x][y] = min(dp[x2][y2][x][y], dp[x2][y2][i][y] + dp[i + 1][y2][x][y]);
          for(int i = y2; i < y; i++)
            dp[x2][y2][x][y] = min(dp[x2][y2][x][y], dp[x2][y2][x][i] + dp[x2][i + 1][x][y]);
        }
  cout << dp[1][1][n][n];
  return 0;
}