#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 20;
int modulo;

struct Matrix{
  int n;
  int m;
  vector<vector<int>> mat;
  Matrix(int n_ = 0, int m_ = 0){
    n = n_;
    m = m_;
    mat.resize(n);
    for(int i = 0; i < n; i++)
      mat[i].resize(m);
  }

  Matrix operator * (Matrix const a) const{
    //assert(m == a.n);
    Matrix result(n, a.m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < a.m; j++)
        for(int h = 0; h < m; h++) {
          result.mat[i][j] += 1LL * mat[i][h] * a.mat[h][j] % modulo;
          if(modulo <= result.mat[i][j])
            result.mat[i][j] -= modulo;
        }
    return result;
  }
};

Matrix lgpow(Matrix a, ll b){
  if(b == 0){
    Matrix result(a.n, a.n);
    for(int i = 0; i < a.n; i++)
      result.mat[i][i] = 1;
    return result;
  } else {
    Matrix result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}
int comb[1 + nmax][1 + nmax];

void computecomb(int modulo){
  comb[0][0] = 1;
  for(int i = 1;i <= nmax; i++) {
    comb[i][0] = 1;
    for(int j = 1;j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(modulo <= comb[i][j])
        comb[i][j] -= modulo;
    }
  }
}

int getcomb(int n, int k){
  if(0 <= k && k <= n)
    return comb[n][k];
  else
    return 0;
}

int original[1 + (1<<nmax)], coef[1 + nmax];
int dp[1 + nmax][1 + (1<<nmax)], dp2[1 + nmax][1 + (1 << nmax)];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m;
  ll t;
  cin >> m >> t >> modulo;
  computecomb(modulo);
  for(int i = 0; i < (1 << m); i++)
    cin >> original[i];
  for(int i = 0; i <= m; i++)
    cin >> coef[i];
  Matrix contrib(1 + m, 1 + m);

  for(int i = 0; i <= m; i++)
    for(int repair = 0; repair <= m - i; repair++)
      for(int smash = 0; smash <= i; smash++)
        if(i + repair - smash <= m) {
          contrib.mat[i][i + repair - smash] += 1LL * getcomb(i, smash) * getcomb(m - i, repair) % modulo * coef[repair + smash] % modulo;
          if(modulo <= contrib.mat[i][i + repair - smash])
            contrib.mat[i][i + repair - smash] -= modulo;
        }


  contrib = lgpow(contrib, t);

  Matrix contribtotal[1 + nmax];
  for(int i = 0; i <= m; i++) {
    contribtotal[i] = Matrix(1 + m, 1 + m);
    contribtotal[i].mat[0][i] = 1;
    contribtotal[i] = contribtotal[i] * contrib;
  }


  for(int i = 0; i <= m; i++)
    coef[i] = contribtotal[i].mat[0][0];

  for(int mask = 0; mask < (1 << m); mask++)
    dp[0][mask] = original[mask] % modulo;


  for(int i = 1;i <= m; i++) {
    for(int bits = 0; bits <= i; bits++)
      for(int mask = 0; mask < (1 << m); mask++){
        dp2[bits][mask] = dp[bits][mask];
        if(0 < bits) {
          dp2[bits][mask] += dp[bits - 1][mask ^ (1 << (i - 1))];
          if(modulo <= dp2[bits][mask])
            dp2[bits][mask] -= modulo;
        }
      }
    for(int bits = 0; bits <= i; bits++)
      for(int mask = 0; mask < (1 << m); mask++) {
        dp[bits][mask] = dp2[bits][mask];
        dp2[bits][mask] = 0;
      }
  }

  for(int mask = 0; mask < (1 << m); mask++){
    int result = 0;
    for(int bits = 0; bits <= m; bits++) {
      result += 1LL * dp[bits][mask] * coef[bits] % modulo;
      if(modulo <= result)
        result -= modulo;
    }
    cout << result << '\n';
  }
  return 0;
}