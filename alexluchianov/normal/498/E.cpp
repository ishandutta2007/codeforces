#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using ll = long long;

int const modulo = 1000000007;

class Matrix{
private:
  int n;
public: 
  std::vector<std::vector<int>> mat;
  Matrix(int n_ = 0) {
    n = n_;
    mat.resize(n);
    for(int i = 0; i < n; i++) 
      mat[i].resize(n);
  }
  Matrix operator * (Matrix oth) const {
    assert(n == oth.n);
    Matrix result(n);
    for(int i = 0; i < n; i++)
      for(int h = 0; h < n; h++)
        for(int j = 0; j < n; j++)
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * oth.mat[h][j]) % modulo;  
    return result;
  }
};

Matrix generate(int n) {
  Matrix result((1 << n));
  for(int mask = 0; mask < (1 << n); mask++)
    for(int mask2 = 0; mask2 < (1 << n); mask2++) {
      int sol = 0;
      for(int mask3 = 1; mask3 < (1 << n); mask3 += 2) 
        if((mask & mask2 & mask3 & ((mask3 + (1 << n)) >> 1)) == 0)
          sol++;
      result.mat[mask][mask2] = sol;
    }
  return result;
}

int const sigma = 7;
Matrix step[1 + sigma];

Matrix lgpow(Matrix a, int b) {
  assert(0 < b);
  if(b == 1) {
    return a;
  } else {
    Matrix result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

int main() {
  for(int i = 1;i <= sigma; i++)
    step[i] = generate(i);
  
  int last = 0;
  Matrix base;
  for(int i = 1;i <= sigma; i++) {
    int val;
    std::cin >> val;
    if(0 < val) {
      if(0 == last) {
        base = Matrix((1 << i));
        base.mat[0][(1 << i) - 1] = 1;
      } else {
        Matrix secbase = Matrix(1 << i);
        for(int j = 0; j < (1 << last); j++)
          secbase.mat[0][j ^ ((1 << i) - 1) ^ ((1 << last) - 1)] = base.mat[0][j];
        base = secbase;
      }
      base = base * lgpow(generate(i), val);
      last = i;
    }
  }

  assert(0 < last);
  std::cout << base.mat[0][(1 << last) - 1] << '\n';
  return 0;
}