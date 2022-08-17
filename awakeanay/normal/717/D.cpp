#include <iostream>
#include <vector>

#define int long long
int n, x = 127;

std::vector<long double> add(std::vector<long double> a, std::vector<long double> b) {
  std::vector<long double> c(x+1, 0.0f);

  for(int i = 0; i <= x; i++) {
    for(int j = 0; j <= x; j++) {
      c[i^j] += a[i]*b[j];
    }
  }

  return c;
}

signed main() {
  int y;
  std::cin >> n >> y;

  std::vector<long double> p[33];
  for(int i = 0; i < 33; i++)
    p[i] = std::vector<long double>(x+1, 0.0);
  for(int i = 0; i <= y; i++)
    std::cin >> p[0][i];
  for(int i = y+1; i <= x; i++)
    p[0][i] = 0.0f;

  for(int i = 1; i < 33; i++) {
    p[i] = add(p[i-1], p[i-1]);
  }

  std::vector<long double> ans(x+1, 0.0f);
  ans[0] = 1.0f;

  for(int i = 32; i >= 0; i--) {
    if((n >> i)&(1ll)) {
      ans = add(ans, p[i]);
    }
  }

  std::cout << 1.0f - ans[0] << std::endl;

  return 0;
}