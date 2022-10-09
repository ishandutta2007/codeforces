#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

using ll = long long;
int const nmax = 16;
int const modulo = 1000000007;

class Matrix{
//indexed from 1
private:
  int n, m;
  using ll = long long;
public:
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
        for(int h = 1; h <= m; h++)
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][h] * a.mat[h][j]) % modulo;
    return result;
  }

  Matrix lgpow(Matrix a, ll b){
    if(b == 0){
      Matrix result(a.n, a.m);
      for(int i = 1;i <= a.n; i++)
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
  Matrix operator ^ (ll b){
    return lgpow(*this, b);
  }
};

Matrix lim(int val){
  Matrix result(nmax, nmax);
  for(int i = 1;i <= val; i++){
    if(1 <= i - 1)
      result.mat[i - 1][i] = 1;
    result.mat[i][i] = 1;
    if(i + 1 <= nmax)
      result.mat[i + 1][i] = 1;
  }
  return result;
}

int main()
{
  Matrix init(nmax, nmax);
  init.mat[1][1] = 1;///pentru punctul 0
  int n;
  ll k;
  cin >> n >> k;
  int last = 20;
  ll step = 0;
  for(int i = 1;i <= n; i++){
    ll a, b;
    int c;
    cin >> a >> b >> c;
    c++;
    if(i == n)
      b = k + 1;
    if(1 < i) {
      init = init * lim(min(c, last));
      step++;
    }
    init = init * (lim(c) ^ (b - a - 1));
    step += (b - a - 1);
    last = c;
  }
  assert(step == k);
  cout << init.mat[1][1];
  return 0;
}