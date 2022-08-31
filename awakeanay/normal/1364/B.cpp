#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::vector<int> ans;
    ans.push_back(0);

    for(int i = 1; i < n; i++) {
      if(i == n-1 || ((a[i+1] < a[i]) ^ (a[i] < a[i-1])))
         ans.push_back(i);
    }

    std::cout << ans.size() << std::endl;
    for(int j : ans)
      std::cout << a[j] << " ";
    std::cout << std::endl;

  }

  return 0;
}