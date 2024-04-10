#include <iostream>
#include <vector>

#define int long long

const int MOD = 998244353;

std::vector<std::vector<int> > mult(const std::vector<std::vector<int> > &a, const std::vector<std::vector<int> > &b) {
  auto ret = a;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      ret[i][j] = 0;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++)
        ret[i][k] = (b[i][j]*a[j][k] + ret[i][k])%MOD;
  return ret;
}

std::vector<std::vector<int> > expo(std::vector<std::vector<int> > x, int p) {
  std::vector<std::vector<int> > ret = {{1, 0}, {0, 1}};

  while(p > 0ll) {
    if(p&1ll)
      ret = mult(ret, x);

    p >>= 1ll;
    x = mult(x, x);
  } 

  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, l, r;
  std::cin >> n >> m >> l >> r;

  int a = (r-l+1)/2ll;
  int b = (r-l+1-a);

  if(!(l&1ll))
    a ^= b ^= a ^= b;

  a %= MOD;
  b %= MOD;

  std::vector<std::vector<int> > mat = {{a, b}, {b, a}};
  mat = expo(mat, n*m);
  int ans = mat[0][0];
  if((n*m)%2 != 0) {
    std::vector<std::vector<int> > mat2 = {{b, a}, {a, b}};
    mat2 = expo(mat2, n*m);
    ans += mat2[0][0];
    ans %= MOD;
  }

  std::cout << (ans)%MOD << std::endl;

  return 0;
}