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

    int num = 1;
    for(int i = 0; i < n; i++)
      num *= 3;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] < 0)
        a[i] = -a[i];
    }

    bool poss = false;
    for(int i = 1; i < num; i++) {
      int val = i;
      int cur = 0;
      for(int j = 0; j < n; j++) {
        if(val%3 == 1)
          cur += a[j];
        else if(val%3 == 2)
          cur -= a[j];
        val /= 3;
      }

      if(cur == 0)
        poss = true;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}