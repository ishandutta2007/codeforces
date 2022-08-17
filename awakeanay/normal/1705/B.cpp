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

    int a[n];
    std::set<int> zeros;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] == 0)
        zeros.insert(i);
    }

    int ans = 0;
    for(int i = 0; i+1 < n; i++) {
      while(a[i]) {
        if(zeros.empty()) {
          ans += a[i];
          a[i] = 0;
        }
        else {
          a[i]--;
          ans += 1;
          int u = *zeros.begin();
          a[u]++;
          zeros.erase(zeros.begin());
        }
      }
      zeros.erase(i);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}