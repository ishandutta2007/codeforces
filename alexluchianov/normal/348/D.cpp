#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 3000;
int const modulo = 1000000007;
char v[1 + nmax][1 + nmax];
int dp[1 + nmax][1 + nmax];

int solve(int x, int y, int x2, int y2){
  for(int i = 1;i <= x2; i++)
    for(int j = 1;j <= y2; j++)
      dp[i][j] = 0;
  dp[x][y] = 1;
  for(int i = 1;i <= x2; i++)
    for(int j = 1; j <= y2; j++) {
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      if(modulo <= dp[i][j])
        dp[i][j] -= modulo;
      if(v[i][j] == '#')
        dp[i][j] = 0;
    }
  return dp[x2][y2];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> v[i][j];
  int result = 1LL * solve(1, 2, n - 1, m) * solve(2, 1, n, m - 1) % modulo;
  int result2 = 1LL * solve(1, 2, n, m - 1) * solve(2, 1, n - 1, m) % modulo;
  cout << (modulo + result - result2) % modulo;
  return 0;
}