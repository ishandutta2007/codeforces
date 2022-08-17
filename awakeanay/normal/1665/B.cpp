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

    int max = 0;
    std::map<int, int> ct;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ct[x]++;
      max = std::max(ct[x], max);
    }

    int op = 0;
    while(max < n) {
      op++;
      int next = std::min(2*max, n);
      op += next - max;
      max = next;
    }

    std::cout << op << std::endl;
  }

  return 0;
}