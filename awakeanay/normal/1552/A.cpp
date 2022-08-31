#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a;
    b = a;

    std::sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
      if(a[i] != b[i])
        ans++;

    std::cout << ans << std::endl;
  }

  return 0;
}