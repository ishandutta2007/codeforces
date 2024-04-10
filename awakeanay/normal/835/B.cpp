#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int k;
  std::cin >> k;

  std::string n;
  std::cin >> n;

  std::sort(n.begin(), n.end());

  int cur = 0;
  for(int i = 0; i < n.length(); i++) {
    cur += n[i] - '0';
  }

  int ans = 0;
  while(cur < k) {
    cur +=  9 - (n[ans++] - '0');
  }

  std::cout << ans << std::endl;
}