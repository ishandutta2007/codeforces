#include <iostream>

#define int long long

int k;

int add(int x, int y, int yinv) {
  int ret = 0;
  int mult = 1;
  while(x > 0 || y > 0) {
    int x1 = x%k, y1 = y%k;
    if(yinv)
      y1 = (k-y1)%k;
    ret += ((x1+y1)%k)*mult;
    mult *= k;
    x /= k;
    y /= k;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  k = 2;
  while(t--) {
    int n;
    std::cin >> n >> k;

    int sub[2] = {0, 0};
    for(int i = 0; i < n; i++) {
      int guess = i;
      if(i%2)
        guess = add(0, i, 1);
      guess = add(guess, sub[1-i%2], 0);
      guess = add(guess, sub[i%2], 1);
      std::cout << guess << std::endl;
      int r;
      std::cin >> r;
      if(r != 0)
        break;
      sub[i%2] = add(sub[i%2], guess, 0);
    }
  }

  return 0;
}