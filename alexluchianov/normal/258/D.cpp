#include <iostream>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[1 + nmax];
ld dp[1 + nmax][1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];

  for(int i = 1;i <= n; i++)
    for(int j = i + 1;j <= n; j++)
      dp[i][j] = v[j] < v[i];
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    if(x == y)
      continue;
    if(y < x)
      swap(x, y);
    dp[x][y] = 1 / 2.0 * dp[x][y] + (1 / 2.0) * (1 - dp[x][y]);
    for(int i = 1;i < x; i++){
      ld a, b;
      a = 1 / 2.0 * dp[i][x] + (1 / 2.0) * (dp[i][y]);
      b = 1 / 2.0 * dp[i][y] + (1 / 2.0) * (dp[i][x]);
      dp[i][x] = a;
      dp[i][y] = b;
    }
    for(int i = x + 1; i < y; i++){
      ld a, b;
      a = 1 / 2.0 * (dp[x][i]) + 1 / 2.0 * (1 - dp[i][y]);
      b = 1 / 2.0 * (dp[i][y]) + 1 / 2.0 * (1 - dp[x][i]);

      dp[x][i] = a;
      dp[i][y] = b;
    }
    for(int i = y + 1; i <= n; i++){
      ld a, b;
      a = 1 / 2.0 * (dp[x][i]) + 1 / 2.0 * (dp[y][i]);
      b = 1 / 2.0 * (dp[y][i]) + 1 / 2.0 * (dp[x][i]);
      dp[x][i] = a;
      dp[y][i] = b;
    }
  }
  ld result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      result += dp[i][j];
  cout << setprecision(10) << fixed << result;
  return 0;
}