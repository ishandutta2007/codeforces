#include <iostream>
#include <vector>

signed main() {
  int n;
  std::cin >> n;

  int reva[n];
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    reva[x] = i;
  }

  std::vector<int> ans(n, 0);
  int max = 0;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    int cur = (i - reva[x] + n)%n;
    ans[cur]++;
    max = std::max(max, ans[cur]);
  }

  std::cout << max << std::endl;
  return 0;
}