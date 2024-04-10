#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ct = 0;
  int x = 0, y = 0;

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      if(c == 'B') {
        x += i;
        y += j;
        ct++;
      }
    }
  }

  std::cout << (x/ct)+1 << " " << (y/ct)+1 << std::endl;

  return 0;
}