#include <iostream>

#define int long long

const int LOG = 20;

int gcd(int x, int y) {
  if(x == 0)
    return y;
  return gcd(y%x, x);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int done = true;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] != a[0])
        done = false;
    }

    if(done) {
      std::cout << 0 << std::endl;
      continue;
    }

    int gst[LOG][n];
    for(int i = 0; i < n; i++) {
      gst[0][i] = a[i];
      //std::cout << gst[0][i] << " ";
    }
    //std::cout << std::endl;

    for(int i = 1; i < LOG; i++) {
      for(int j = 0; j < n; j++) {
        gst[i][j] = gcd(gst[i-1][j], gst[i-1][(j+(1 << (i-1)))%n]);
      }
    }

    int first[n+1];
    first[1] = 0;
    for(int i = 2; i <= n; i++)
      first[i] = first[i/2] + 1;

    int lo = 1, hi = n-1;
    while(lo < hi) {
      int mid = (lo+hi)/2;

      int val[n];
      bool check = true;
      int fm = first[mid+1];
      for(int i = 0; i < n; i++) {
        //std::cout << mid+1 << " " << i << " " << fm << " " << (i+mid-(1 << fm)+1) << std::endl;
        val[i] = gcd(gst[fm][i], gst[fm][(i+mid-(1 << fm)+1+n)%n]);
        //std::cout << gst[fm][i] << " " << gst[fm][(i+mid-(1 << fm)+1+3*n)%n] << std::endl;
        //std::cout << val[i] << std::endl;
        if(val[i] != val[0])
          check = false;
      }

      if(check)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}