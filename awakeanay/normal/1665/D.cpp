#include <iostream>

#define int long long

int query(int a, int b) {
  std::cout << "? " << a << " " << b << std::endl;
  int x;
  std::cin >> x;
  return x;
}

const int LOG = 32;

int p2[LOG];
int MAX = 2000'000'000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  p2[0] = 1;
  for(int i = 1; i < LOG; i++)
    p2[i] = (2ll)*p2[i-1];

  while(t--) {
    int last = 0;
    int ch = 0;
    for(int i = 1; i <= 30; i++) {
      int use = -1;
      int x = p2[i-1]-last;
      int y = p2[i];

      if(0 < y-x && y-x <= MAX)
        use = y-x;
      if(0 < x+y && x+y <= MAX)
        use = x+y;

      int res = query(p2[i-1]-last, use);
      if((res == p2[i])) {
        last ^= p2[i-1];
        ch = 1;
      }
      else
        ch = 0;
    }

    std::cout << "! " << last << std::endl;
  }

  return 0;
}