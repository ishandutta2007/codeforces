#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const n = 10;
int v[5 + n][5 + n];
int h[5 + n][5 + n];

void precompute(){
  int x = n, y = 1, steps = 0;
  int dir = 1;
  while(0 < x){
    v[x][y] = ++steps;
    if(1 <= y + dir && y + dir <= n)
      y += dir;
    else{
      dir = -dir;
      x--;
    }
  }
}
ld dp[10 + n * n], dp2[10 + n * n];
int lad[10 + n * n];

int main()
{

  precompute();
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      cin >> h[i][j];
      lad[v[i][j]] = v[i - h[i][j]][j];
    }

  for(int i = n * n - 1;1 <= i; i--){
    for(int j = 1; j <= 6; j++)
      if(i + j <= n * n)
        dp[i] += 1.0 / 6 * (dp2[i + j] + 1);

    if(n * n - 6 < i) {
      ld exp = (6.0 - (n * n - i)) / 6.0;
      dp[i] = (dp[i] + exp) / (1 - exp);
    }

    dp2[i] = dp[i];
    dp2[i] = min(dp[i], dp[lad[i]]);
  }
  cout << setprecision(6) << fixed << dp2[1];
  return 0;
}
/*
1
2
1 1 0
RR
*/