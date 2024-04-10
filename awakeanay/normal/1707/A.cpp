#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 100005;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, q;
    std::cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    
    int lo = 1, hi = n+1;
    while(lo < hi) {
      int cq = q;
      int mid = (lo+hi)/2;
      int st = n-mid;
      for(int j = st; j < n; j++) {
        if(a[j] > cq)
          cq--;
      }

      if(cq < 0)
        hi = mid;
      else
        lo = mid+1;
    }

    std::string s(n, '0');
    lo--;
    for(int j = 0; j < n; j++) {
      s[n-1-j] = (j < lo || a[n-1-j] <= q) + '0';
    }
    std::cout << s << "\n";
  }

  return 0;
}