#include <iostream>
#include <map>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> last, count;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      count[x] += last[x];
      ans += (n-i)*count[x];
      last[x] = i+1;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}