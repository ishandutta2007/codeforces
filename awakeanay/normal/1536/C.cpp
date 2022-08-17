#include <iostream>
#include <map>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, int> mp;
    int d = 0, k = 0;
    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      if(c == 'D')
        d++;
      else
        k++;
      int gd = gcd(d, k);

      std::pair<int, int> cur = {d/gd, k/gd};
      mp[cur]++;
      std::cout << mp[cur] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}