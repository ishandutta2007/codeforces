#include <iostream>

#define int long long

const int LOG = 20;
const int MAXN = 200005;

int pr[LOG][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 1; i < MAXN; i++) {
    for(int j = 0; j < LOG; j++) {
      pr[j][i] = pr[j][i-1] + ((i >> j)&1);
    }
  }

  int t;
  std::cin >> t;
  
  while(t--) {
    int l, r;
    std::cin >> l >> r;
    l--;

    int max = 0;
    for(int i = 0; i < LOG; i++)
      max = std::max(max, pr[i][r]-pr[i][l]);

    std::cout << (r-l-max) << std::endl;
  }

  return 0;
}