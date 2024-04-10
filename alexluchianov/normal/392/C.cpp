#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 40;
int const modulo = 1000000007;

class Matrix {
public:
  int n, m;
  std::vector<std::vector<int>> mat;
  Matrix(int n_ = 0, int m_ = 0) {
    n = n_;
    m = m_;
    mat.resize(n);
    for(int i = 0; i < n; i++)
      mat[i].resize(m);
  }
  Matrix operator * (Matrix a) {
    Matrix result(n, a.m);
    assert(m == a.n);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < a.m; j++)
        for(int h = 0; h < a.n; h++)
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * a.mat[h][j]) % modulo;
    return result;
  }
};

int comb[1 + nmax][1 + nmax];

void precompute() {
  comb[0][0] = 1;
  for(int i = 1;i <= nmax; i++){
    comb[i][0] = 1;
    for(int j = 1;j <= i; j++) 
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modulo;
  }
}

Matrix lgpow(Matrix a, ll b) {
  if(b == 0) {
    Matrix result(a.n, a.m);
    for(int i = 0; i < a.n; i++)
      result.mat[i][i] = 1;
    return result;
  } else if(b == 1)
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
  precompute();
  ll n, k;
  std::cin >> n >> k;
  Matrix basic(k * 2 + 3, k * 2 + 3);
  for(int i = 0; i <= 2 * k + 2; i++)
    basic.mat[0][i] = 1;
  Matrix step(k * 2 + 3, k * 2 + 3), step2(k * 2 + 3, k * 2 + 3);
  for(int i = 0; i <= k; i++) {
    step.mat[i + k + 1][i] = 1;
    step.mat[i + k + 1][i + k + 1] = 1;
    step.mat[i][i + k + 1] = 1;
  }
  step.mat[2 * k + 2][2 * k + 2] = 1;
  for(int i = 0; i <= k; i++) {
    for(int j = 0; j <= i; j++) {
      step2.mat[j][i] = comb[i][j];
      step2.mat[j + k + 1][i + k + 1] = comb[i][j];
    }
  }
  step2.mat[2 * k + 2][2 * k + 2] = 1;
  for(int j = 0; j < 2 * k + 2; j++)
    step2.mat[j][2 * k + 2] = step2.mat[j][2 * k + 1];
  step = step * step2;
  basic = basic * lgpow(step, n - 1);
  std::cout << basic.mat[0][2 * k + 2];
}