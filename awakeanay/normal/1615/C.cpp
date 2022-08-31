#include <iostream>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
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

    int best = n+1;
    std::string a, b;
    std::string zero = std::string(n, '0');
    std::cin >> a >> b;

    if((a == zero)^(b == zero)) {
      std::cout << -1 << std::endl;
      continue;
    }

    int ch = 0, nch = 0;
    int chz = 0, chn = 0;
    int nchz = 0, nchn = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] != b[i]) {
        ch++;
        if(a[i] == '1')
          chn++;
        else
          chz++;
      }
      else {
        nch++;
        if(a[i] == '1')
          nchn++;
        else
          nchz++;
      }
    }

    if(ch%2 == 0) {
      if(chn == chz || chn == chz + 1)
        best = std::min(best, chz + chn);
    }
    
    if(nch%2 == 1) {
      if(nchn == nchz || nchn == nchz + 1)
        best = std::min(best, nchn + nchz);
    }

    std::cout << (best < n+1 ? best : -1) << std::endl;
  }

  return 0;
}