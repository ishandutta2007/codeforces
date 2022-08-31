#include <iostream>
#include <map>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::map<int, int> m;
  int ans = 0;
  m[0] = 1;
  int cur = 0;
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cur += x;
    if(m[cur]) {
      ans++;
      m.clear();
      cur = x;
      m[cur] = 1;
      m[0] = 1;
    }
    else m[cur] = 1;
  }

  std::cout << ans << std::endl;

  return 0;
}