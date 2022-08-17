#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int pre[n], suf[n];
    for(int i = 0; i < n; i++)
      std::cin >> pre[i];

    for(int i = n-1; i >= 0; i--) {
      suf[i] = pre[i];
      if(i+1 < n)
        suf[i] = std::min(suf[i], suf[i+1]);
    }

    bool poss = false;
    for(int i = 1; i < n; i++) {
      pre[i] = std::max(pre[i], pre[i-1]);
      if(pre[i-1] > suf[i])
        poss = true;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}