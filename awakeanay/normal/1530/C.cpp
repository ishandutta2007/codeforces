#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    std::sort(b, b+n);
    std::sort(a, a+n);
    std::reverse(b, b+n);
    std::reverse(a, a+n);

    for(int i = 1; i < n; i++) {
      a[i] += a[i-1];
      b[i] += b[i-1];
    }

    int lo = 0, hi = n;
    while(lo < hi) {
      int mid = (lo&hi) + ((lo^hi) >> 1);
      int t = n+mid;
      int ct = t - t/4;

      int k1 = std::min(ct, n);
      int ilc = b[k1-1];
      int k2 = std::min(mid, ct);
      int myc = k2*100;
      int rem = ct-k2;
      if(rem)
        myc += a[rem-1];


      if(myc >= ilc)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}