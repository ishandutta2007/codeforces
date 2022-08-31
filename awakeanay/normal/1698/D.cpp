#include <iostream>

#define int long long

int query(int l, int r) {
  std::cout << "? " << l+1 << " " << r+1 << std::endl;
  int m = r-l+1;
  int tot = 0;
  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    if(l+1 <= x && x <= r+1)
      tot++;
  }
  return tot&1;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int l = 0, r = n-1;
    while(l < r) {
      int m = (l+r)/2;
      if(query(l, m))
        r = m;
      else
        l = m+1;
    }

    std::cout << "! " << l+1 << std::endl;
  }

  return 0;
}