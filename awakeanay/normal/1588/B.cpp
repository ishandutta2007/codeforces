#include <iostream>
#include <map>

#define int long long

int query(int l, int r) {
  std::cout << "? " << l+1 << " " << r+1 << std::endl;
  int x;
  std::cin >> x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int fi;
    int lo = 1, hi = n-3;

    while(lo < hi) {
      int mid = (lo+hi)/2;
      if(query(0, mid))
        hi = mid;
      else
        lo = mid+1;
    }

    fi = lo-1;

    int aq = query(fi, n-1);
    int bq = query(fi+1, n-1);

    int fj = fi+aq-bq+1;

    aq = query(fj, n-1);
    bq = query(fj+1, n-1);

    int fk = fj+aq-bq;

    std::cout << "! " << fi+1 << " " << fj+1 << " " << fk+1 << std::endl;
  }

  return 0;
}