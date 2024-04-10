#include <iostream>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 600;
int l[5 + nmax], r[5 + nmax];
int dp[5 + nmax][5 + nmax];

void solve(int x, int y){
  if(y < x)
    return ;

  cout << "(";
  for(int k = x + 1; k <= y + 1; k++){
    if(l[x] <= (k - x - 1) * 2 + 1 && (k - x - 1) * 2 + 1 <= r[x]) {
      if((dp[x + 1][k - 1] & dp[k][y]) == 1) {
        solve(x + 1, k - 1);
        cout << ")";
        solve(k, y);
        return ;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> l[i] >> r[i];
  for(int i = 1;i <= n + 1; i++)
    dp[i][i - 1] = 1;

  for(int h = 0; h <= n; h++) {
    for(int i = 1;i <= n; i++) {
      int j = i + h;
      if(j <= n){
        for(int k = i + 1; k <= j + 1; k++)
          if(l[i] <= (k - i - 1) * 2 + 1 && (k - i - 1) * 2 + 1 <= r[i]) {
            dp[i][j] |= (dp[i + 1][k - 1] & dp[k][j]);
          }
      }
    }
  }
  if(dp[1][n] == 0)
    cout << "IMPOSSIBLE\n";
  else
    solve(1, n);

  return 0;
}