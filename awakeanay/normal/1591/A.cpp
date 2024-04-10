#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int h = 1;
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int die = 0;
    for(int i = 0; i+1 < n; i++)
      if(a[i] == a[i+1] && a[i] == 0)
        die = 1;

    if(die) {
      std::cout << -1 << std::endl;
      continue;
    }

    int l = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] && l)
        h += 5;
      else if(a[i])
        h += 1;
      l = a[i];
    }

    std::cout << h << std::endl;
  }

  return 0;
}