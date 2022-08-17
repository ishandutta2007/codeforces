#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> count(n+1);
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i && a[i] == a[i-1])
        count[a[i]]--;
      count[a[i]]++;
    }

    int ans = n+1;
    for(int i = 1; i <= n; i++) {
      if(count[i])
        ans = std::min(ans, count[i]+1-(a[0] == i)-(a[n-1] == i));
    }

    std::cout << ans << std::endl;
  }
      
  return 0;
}