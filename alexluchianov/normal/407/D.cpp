#include <iostream>
#include <fstream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 400;
int v[1 + nmax][1 + nmax];
int dp[1 + nmax][1 + nmax];
int frec[1 + nmax * nmax], frec2[1 + nmax * nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];

  int result = 0;
  for(int i = 1;i <= n; i++){
    for(int j = 1;j <= m; j++){
      dp[i][j] = MAX(dp[i][j - 1], frec[v[i][j]] + 1);
      result = MAX(result, j - dp[i][j] + 1);
      frec[v[i][j]] = j;
    }
    for(int j = 1;j <= m; j++)
      frec[v[i][j]] = 0;
  }

  for(int idif = 1;idif < n; idif++)
    for(int i = 1;i <= n - idif; i++){
      int i2 = i + idif;
      for(int j = 1;j <= m; j++){
        frec[v[i][j]] = j;
        frec2[v[i2][j]] = j;
        dp[i][j] = MAX(dp[i][j - 1], MAX(dp[i][j], dp[i + 1][j]));
        dp[i][j] = MAX(dp[i][j], MAX(frec[v[i2][j]] + 1, frec2[v[i][j]] + 1));
        result = MAX(result, (i2 - i + 1) * (j - dp[i][j] + 1));
      }
      for(int j = 1; j <= m; j++)
        frec[v[i][j]] = frec2[v[i2][j]] = 0;
    }
  cout << result;
  return 0;
}