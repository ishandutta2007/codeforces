#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n+1];
    a[n] = n+1;
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int b[n+1];
    int last[n+1] = {0};
    b[n] = 1;
    for(int i = n-1; i >= 0; i--) {
      b[i] = b[i+1] & (a[i] <= a[i+1]);
    }
    for(int i = 0; i < n; i++)
      last[a[i]] = i;

    if(b[0]) {
      std::cout << 0 << std::endl;
      continue;
    }

    int max = 0;
    int ans = n;
    std::set<int> dist;
    for(int i = 0; i < n; i++) {
      dist.insert(a[i]);
      max = std::max(max, last[a[i]]);
      if(max <= i && b[i+1]) {
        ans = std::min(ans, (int)dist.size());
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}