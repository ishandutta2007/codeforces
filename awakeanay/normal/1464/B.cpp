#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::string s;
  std::cin >> s;

  int x, y;
  std::cin >> x >> y;

  int n = s.length();

  if(n == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  std::vector<int> mark(n, 0);
  int cur = 0;
  int ones = 0, zeroes = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '?') {
      s[i] = (x > y) ? '0' : '1';
      mark[i] = true;
    }

    if(s[i] == '0') {
      zeroes++;
      cur += ones*y;
    }
    else {
      ones++;
      cur += zeroes*x;
    }
  }

  int ans = cur;

  int l0s = 0;
  int r0s = 0;
  for(int i = n-1; i >= 0; i--) {
    r0s += (s[i] == '0');
  }

  for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
      r0s--;
    }

    int l1s = i-l0s;
    int r1s = n-i-1-r0s;

    if(mark[i]) {
      int val[2];
      val[0] = x*r1s + y*l1s;
      val[1] = x*l0s + y*r0s;

      int a = s[i] - '0';
      int b = a^1;
      cur += val[b]-val[a];
      s[i] = '0' + b;
    }

    ans = std::min(ans, cur);

    if(s[i] == '0') {
      l0s++;
    }
  }

  std::cout << ans << std::endl;
  
  return 0;
}