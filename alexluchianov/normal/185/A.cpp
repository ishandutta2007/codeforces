#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;
int const modulo = 1000000007;

struct Matrix{
  int mat[2][2] = {0};
  Matrix operator * (Matrix const &oth) const {
    Matrix result;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int h = 0; h < 2; h++)
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * oth.mat[h][j]) % modulo;
    return result;
  }
};

Matrix lgpow(Matrix a, ll b) {
  if(b == 1)
    return a;
  else {
    Matrix result = lgpow(a , b/ 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

int main() {
  Matrix init;
  init.mat[0][0] = 0;
  init.mat[0][1] = 1;
  ll n;
  std::cin >> n;
  if(n == 0) {
    std::cout << 1;
    return 0;
  }
  Matrix aux;
  aux.mat[1][0] = 1;
  aux.mat[1][1] = 3;
  aux.mat[0][1] = 1;
  aux.mat[0][0] = 3;
  std::cout << (init * lgpow(aux, n)).mat[0][1];
  return 0;
}