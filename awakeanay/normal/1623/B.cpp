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

    std::vector<int> ct(n+1, 0);
    int l[n], r[n];
    for(int i = 0; i < n; i++) {
      std::cin >> l[i] >> r[i];
      for(int j = l[i]; j <= r[i]; j++)
        ct[j]++;
    }

    for(int i = 0; i < n; i++) {
      int min = n+1, val = -1;
      for(int j = l[i]; j <= r[i]; j++) {
        if(ct[j] < min) {
          min = ct[j];
          val = j;
        }
      }

      std::cout << l[i] << " " << r[i] << " " << val << std::endl;
    }
  }

  return 0;
}