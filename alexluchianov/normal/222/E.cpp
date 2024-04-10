#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 1000000007;

class Matrix{
public:
  int n;
  int m;
  vector<vector<int>> v;
  Matrix(int n = 0, int m = 0){
    this->n = n;
    this->m = m;
    v.resize(1 + n);
    for(int i = 1;i <= n; i++)
      v[i].resize(1 + m);
  }
  Matrix operator * (Matrix const &a) const{
    assert(m == a.n);
    Matrix result(n, a.m);
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= a.m; j++)
        for(int h = 1; h <= m; h++) {
          result.v[i][j] += 1LL * v[i][h] * a.v[h][j] % modulo;
          if(modulo <= result.v[i][j])
            result.v[i][j] -= modulo;
        }
    return result;
  }
  void neutral(){
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= m; j++)
        v[i][j] = 0;
    for(int i = 1;i <= n; i++)
      v[i][i] = 1;
  }
};

Matrix lgpow(Matrix a, ll b){
  if(b == 0) {
    Matrix result(a.n, a.m);
    result.neutral();
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

int decode(char ch){
  if('a' <= ch && ch <= 'z')
    return ch - 'a' + 1;
  else
    return ch - 'A' + 1 + 26;
}

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  Matrix init(m, m);
  for(int i = 1;i <= m; i++)
    init.v[1][i] = 1;
  Matrix exp(m, m);
  for(int i = 1;i <= m; i++)
    for(int j = 1;j <= m; j++)
      exp.v[i][j] = 1;

  for(int i = 1;i <= k; i++){
    char ch1, ch2;
    cin >> ch1 >> ch2;
    exp.v[decode(ch1)][decode(ch2)] = 0;
  }
  init = init * lgpow(exp, n - 1);

  int result = 0;
  for(int i = 1;i <= m; i++) {
    result += init.v[1][i];
    if(modulo <= result)
      result -= modulo;
  }

  cout << result;
  return 0;
}