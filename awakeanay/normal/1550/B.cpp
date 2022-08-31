#include <iostream>

#define int long long

const int INF = 1000000000000000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::string s;
    std::cin >> s;

    int min[2];
    min[0] = min[1] = 0;
    min[1] = 1;
    int type = 0;
    for(int i = 1; i < n; i++) {
      if(s[i] != s[i-1]) {
        min[type%2]++;
        type++;
      }
    }

    int num = std::min(min[0], min[1])+1;

    int ans = -INF;
    ans = std::max(ans, n*a + num*b);
    ans = std::max(ans, n*a + n*b);

    std::cout << ans << std::endl;
  }

  return 0;
}