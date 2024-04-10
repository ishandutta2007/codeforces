#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> ct;
    int dist = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ct[x]++;
      if(ct[x] == 1)
        dist++;
    }

    std::cout << (dist - (n%2 != dist%2)) << std::endl;
  }

  return 0;
}