#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, q;
    std::cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++) {
      int cur;
      char c;
      std::cin >> c;
      cur = (c == '+' ? 1 : -1);
      if(i%2)
        cur *= -1;
      a[i] = cur;
      if(i)
        a[i] += a[i-1];
    }

    while(q--) {
      int l, r;
      std::cin >> l >> r;
      l--;
      r--;
      int mult = 1;
      int sum = a[r];
      if(l)
        sum -= a[l-1];
      if(sum < 0) {
        sum *= -1;
        mult = -1;
      }
      if(sum == 0) {
        std::cout << 0 << '\n';
        continue;
      }
      else if(sum%2) {
        std::cout << 1 << '\n';
        int lo = l, hi = r;
        int tar = (sum+1)/2;

        while(lo < hi) {
          int m = (lo+hi)/2;
          int cur = a[m];
          if(l)
            cur -= a[l-1];
          if(mult == -1)
            cur *= -1;

          if(cur >= tar)
            hi = m;
          else
            lo = m+1;
        }

        std::cout << lo+1 << '\n';
      }
      else {
        std::cout << 2 << '\n';
        std::cout << r+1 << " ";
        int ch = a[r-1]-a[r];
        if(mult == -1)
          ch *= -1;
        sum += ch;
        r--;
        int lo = l, hi = r;
        int tar = (sum+1)/2;

        while(lo < hi) {
          int m = (lo+hi)/2;
          int cur = a[m];
          if(l)
            cur -= a[l-1];
          if(mult == -1)
            cur *= -1;

          if(cur >= tar)
            hi = m;
          else
            lo = m+1;
        }

        std::cout << lo+1 << '\n';
      }
    }
  }

  return 0;
}