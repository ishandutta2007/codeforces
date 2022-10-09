#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 1000000007;

class Matrix{
public:
  int n;
  int m;
  vector<vector<int>> mat;
  Matrix(int n, int m){
    this->n = n;
    this->m = m;

    mat.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mat[i].resize(1 + m);
  }
  Matrix operator * (Matrix const &a) const{
    assert(m == a.n);
    Matrix result(n, a.m);
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= a.m; j++)
        for(int h = 1;h <= m; h++) {
          result.mat[i][j] += 1LL * mat[i][h] * a.mat[h][j] % modulo;
          if(modulo <= result.mat[i][j])
            result.mat[i][j] -= modulo;
        }
    return result;
  }
};

Matrix lgpow(Matrix a, int b){
  assert(a.n == a.m);
  if(b == 0){
    Matrix neutral(a.n, a.m);
    for(int i = 1;i <= a.n; i++)
      neutral.mat[i][i] = 1;
    return neutral;
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

int main()
{
  int n;
  cin >> n;
  Matrix init(4, 4);
  init.mat[1][4] = 1;
  Matrix nxt(4, 4);
  for(int i = 1;i <= 4; i++)
    for(int j = 1;j <= 4; j++)
      if(i != j)
        nxt.mat[i][j] = 1;
  cout << (init * lgpow(nxt, n)).mat[1][4];
  return 0;
}