#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 100;
int const modulo = 998244353;
int mat[1 + nmax][1 + nmax], deg[1 + nmax];

int dp[5 + nmax][5 + nmax][5 + nmax];
int sumdp[5 + nmax][5 + nmax][5 + nmax];

class Matrix{
public:
  int mat[5 + nmax * 2][5 + nmax * 2] = {0};
  Matrix() {
    for(int i = 1; i <= nmax * 2; i++)
      for(int j = 1; j <= nmax * 2; j++)
        mat[i][j] = 0; 
  }
  Matrix operator * (Matrix const oth) {
    Matrix result;
    for(int i = 1; i <= nmax * 2; i++)
      for(int j = 1; j <= nmax * 2; j++)
        for(int h = 1; h <= nmax * 2; h++) {
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * oth.mat[h][j]) % modulo;
        }
    return result;
  }
};

Matrix lgpow(Matrix a, int b) {
  if(b == 1)
    return a;
  else {
    Matrix result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    mat[x][y] = mat[y][x] = 1;
    deg[x]++;
    deg[y]++;
  }
  Matrix base;
  for(int i = 1; i <= n; i++)
    base.mat[i][i] = 1;
  Matrix rec;
    
  for(int j = 1;j <= n; j++) {
    rec.mat[n + j][j] = (modulo - deg[j] + 1);
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++)
      rec.mat[j][i] = mat[j][i];
    
    rec.mat[i][n + i] = 1;
  }

  if(1 < k)
    base = base * lgpow(rec, k - 1);
  int result = 0;
  for(int i = 1;i <= n; i++)
    result = (modulo + result - base.mat[i][n + i]) % modulo;
  base = base * rec;
  
  for(int i = 1; i <= n; i++)
    result = (result + base.mat[i][i]) % modulo;
  std::cout << result << '\n';

  /*
  for(int i = 1;i <= n; i++)
    sumdp[0][i][i] = dp[0][i][i] = 1;
  for(int t = 1; t <= k; t++) {
    for(int i = 1;i <= n; i++)
      for(int j = 1; j <= n; j++) {
        if(1 <= t)
          for(int j2 = 1; j2 <= n; j2++)
            sumdp[t][i][j] = (sumdp[t][i][j] + 1LL * sumdp[t - 1][i][j2] * mat[j2][j]) % modulo;
        if(2 <= t)
          sumdp[t][i][j] = (modulo + sumdp[t][i][j] - 1LL * sumdp[t - 2][i][j] * deg[j]) % modulo;
        
        if(2 <= t)
          sumdp[t][i][j] = (sumdp[t - 2][i][j] + sumdp[t][i][j]) % modulo;
        //std::cout << t << " " << i << " " << j << " " << dp[t][i][j] << '\n';
      }
  }
  

  for(int i = 1;i <= n; i++) {
    result += dp[k][i][i];
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << result << '\n';
  */

  return 0;
}