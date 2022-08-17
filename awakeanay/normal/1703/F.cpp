#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> add(n+1, 0);
    int a[n+1];
    for(int i = 1; i <= n; i++)
      std::cin >> a[i];

    int cur = 0;
    int ans = 0;
    for(int i = n; i >= 1; i--) {
      cur += add[i];
      if(a[i] >= i)
        continue;
      ans += cur;
      if(a[i] >= 1)
        add[a[i]-1]++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}