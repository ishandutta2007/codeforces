#include <iostream>

#define int long long

int count[1001];

signed main() {
  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < m; i++)
    count[i] = n/m;

  for(int i = 1; i <= n%m; i++)
    count[i]++;

  int ans = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      if((i*i + j*j)%m == 0) {
        ans += count[i]*count[j];
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}