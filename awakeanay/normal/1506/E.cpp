#include <iostream>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    std::set<int> full;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      full.insert(i+1);
    }

    for(int i = 0; i < n; i++) {
      int cur;
      if(full.count(a[i]))
        cur = a[i];
      else
        cur = *full.begin();
      std::cout << cur << " ";
      full.erase(cur);
    }

    std::cout << std::endl;

    int last = 1;
    for(int i = 0; i < n; i++) {
      for(int j = last; j <= a[i]; j++) {
        full.insert(j);
      }
      last = a[i]+1;
      int cur = *full.rbegin();
      std::cout << cur << " ";
      full.erase(cur);
    }

    std::cout << std::endl;
  }

  return 0;
}