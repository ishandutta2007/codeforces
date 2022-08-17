#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int ans = 0;
  int a[n];
  int b[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    b[i] = 0;
  }

  while(true) {
    int min = 105;
    for(int i = 0; i < n; i++) {
      if(b[i] == 0) {
        min = std::min(a[i], min);
      }
    }

    if(min == 105)
      break;

    for(int j = 0; j < n; j++) {
      if(a[j]%min == 0)
        b[j] = 1;
    }
    ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}