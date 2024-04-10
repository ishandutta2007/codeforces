#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }

    std::vector<int> div;
    for(int i = 1; i*i <= sum; i++) {
      if(sum%i == 0) {
        div.push_back(i);
        if(i*i != sum)
          div.push_back(sum/i);
      }
    }

    std::sort(div.begin(), div.end());

    for(int j : div) {
      int cur = 0;
      int done = true;
      for(int i = 0; i < n; i++) {
        cur += a[i];
        if(cur > j) {
          done = false;
          break;
        }
        else if(cur == j) {
          cur = 0;
        }
      }

      if(done) {
        std::cout << n-sum/j << std::endl;
        break;
      }
    }
  }

  return 0;
}