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

    std::vector<int> ct(10, 0);
    std::vector<int> a;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      x %= 10;
      ct[x]++;
      if(ct[x] <= 3)
        a.push_back(x);
    }

    n = a.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        for(int k = j+1; k < n; k++) {
          if((a[i] + a[j] + a[k])%10 == 3)
            ans = 1;
        }
      }
    }

    std::cout << (ans ? "YES" : "NO") << std::endl;
  }

  return 0;
}