#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;
  while(t--) {
    int n;
    std::cin >> n;
    std::vector<int> alr(n+1, 0);
    int a[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[i] = x;
      alr[x]++;
    }

    int ans = -1;
    for(int i = 0; i <= n; i++)
      if(alr[i] == 1) {
        ans = i;
        break;
      }

    int out = -1;
    for(int i = 0; i < n; i++)
      if(a[i] == ans)
        out = i+1;

    std::cout << out << std::endl;
  }
  return 0;
}