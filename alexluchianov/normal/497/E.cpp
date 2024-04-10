#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 30;
int const modulo = 1000000007;
ll const inf = 1000000000000000000;

struct Matrix{
  int mat[1 + nmax][1 + nmax];
  Matrix() {
    for(int i = 0; i <= nmax; i++)
      for(int j = 0; j <= nmax; j++)
        mat[i][j] = 0;
  }

  Matrix operator * (Matrix oth) {
    Matrix result;
    for(int i = 0; i <= nmax; i++)
      for(int h = 0; h <= nmax; h++) 
        for(int j = 0; j <= nmax; j++) {
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * oth.mat[h][j]) % modulo;
          if(result.mat[i][j] < 0)
            result.mat[i][j] += modulo;
        }
    return result;
  }
};
int const lgmax = 60;
Matrix dp[1 + lgmax][1 + nmax];
int acc[1 + lgmax][1 + nmax];

Matrix secdp[1 + nmax][1 + nmax];
int secacc[1 + nmax][1 + nmax];

int main() {
  ll n;
  int k;
  std::cin >> n >> k;
  Matrix base;
  base.mat[0][k] = 1;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < k; j++)
      dp[0][i].mat[j][j] = 1;
    dp[0][i].mat[k][i] = 1;
    dp[0][i].mat[i][i] = 0;
    dp[0][i].mat[k][k] = 2;
    dp[0][i].mat[i][k] = -1;
    acc[0][i] = (i + 1) % k;
  }
  
  ll target = 1;
  int maxpow = 0;

  for(int h = 1; h < lgmax; h++) {
    if(inf / k < target) {
      break;
    }
    maxpow++;
    target *= k;
    for(int i = 0; i < k; i++) {
      secdp[i][0] = dp[h - 1][i];
      secacc[i][0] = acc[h - 1][i];
    }
    for(int j = 1; (1LL << j) < k; j++) {
      for(int i = 0; i < k; i++) {
        secdp[i][j] = secdp[i][j - 1] * secdp[secacc[i][j - 1]][j - 1];
        secacc[i][j] = secacc[secacc[i][j - 1]][j - 1];
      }
    }
    for(int i = 0; i < k; i++) {
      dp[h][i] = dp[h - 1][i];
      acc[h][i] = (i + 1) % k;
      for(int j = 0; (1LL << j) < k; j++)
        if(0 < ((1LL << j) & (k - 1))) {
          dp[h][i] = dp[h][i] * secdp[acc[h][i]][j];
          acc[h][i] = secacc[acc[h][i]][j];
        }

      acc[h][i] = (acc[h][i] + 1) % k;
    }
  }
  int last = 0, aux = 0;
  for(;maxpow >= 0; maxpow--) {
    while(target <= n) {
      base = base * dp[maxpow][last];
      last = acc[maxpow][last];
      n -= target;
    }
    target /= k;
  }

  std::cout << base.mat[0][k] << '\n';
  return 0;
}