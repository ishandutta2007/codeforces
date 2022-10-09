#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100;
int const modulo = 1000000007;

struct Matrix{
  int n;
  int m;
  vector<vector<int>> mat;
  Matrix(int n_, int m_){
    n = n_;
    m = m_;
    mat.resize(n);
    for(int i = 0; i < n; i++)
      mat[i].resize(m);
  }

  Matrix operator * (Matrix const &a) const{
    assert(m == a.n);
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

Matrix lgpow(Matrix a, int b){
  if(b == 0){
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
int v[1 + nmax];

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  Matrix init(1 + n, 1 + n), coef(1 + n, 1 + n);
  int ones = 0, zeros = 0;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    v[i] = !v[i];
    if(v[i] == 1)
      ones++;
    else
      zeros++;
  }
  int name = 0;
  for(int i = 1;i <= ones; i++)
    name += v[i];
  init.mat[0][name] = 1;

  int x, y;
  gcd(1LL * n * (n - 1) / 2 % modulo , modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;

  for(int i = 0;i <= ones; i++){
    ll smash = 1LL * i * (zeros - (ones - i));
    ll repair = 1LL * (ones - i) * (ones - i);
    ll total = 1LL * n * (n - 1) / 2;

    coef.mat[i][i] = 1LL * (total - smash - repair) % modulo * x % modulo;
    if(1 <= i)
      coef.mat[i][i - 1] = 1LL * smash % modulo * x % modulo;
    if(i + 1 <= ones)
      coef.mat[i][i + 1] = 1LL * repair % modulo * x % modulo;
  }
  cout << (init * lgpow(coef, k)).mat[0][ones] << '\n';
  return 0;
}