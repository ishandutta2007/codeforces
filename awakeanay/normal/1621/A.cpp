#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int m = n-n/2;
    if(k > m) {
      std::cout << -1 << std::endl;
      continue;
    }
    else {
      std::string s[n];
      for(int i = 0; i < n; i++)
        s[i] = std::string(n, '.');

      for(int i = 0; i < k; i++)
        s[2*i][2*i] = 'R';

      for(int i = 0; i < n; i++)
        std::cout << s[i] << std::endl;
    }
  }

  return 0;
}