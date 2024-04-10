#include <iostream>
#include <vector>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];

    std::vector<int> taken(2*n+2, 0);
    std::vector<int> amt(2*n+1, 0);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      amt[a[i]]++;
    }

    for(int i = 1; i <= 2*n; i++) {
      if(amt[i] >= 2) {
        taken[i] = taken[i+1] = 1;
      }
    }

    for(int i = 1; i <= 2*n; i++) {
      if(amt[i] == 1) {
        if(!taken[i])
          taken[i] = 1;
        else
          taken[i+1] = 1;
      }
    }

    int ans = 0;
    for(int i = 1; i <= 2*n+1; i++)
      ans += taken[i];

    std::cout << ans << std::endl;
  }

  return 0;
}