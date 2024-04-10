#include <iostream>

#define int long long

int findg(int a, int b) {
  if(b == 0)
    return a;
  return findg(b, a%b);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int m, d, w;
    std::cin >> m >> d >> w;

    int min = std::min(m, d);

    int gcd = findg(d-1, w);


    if(gcd == w || gcd == 0) {
      std::cout << (min*(min-1))/2 << std::endl;
      continue;
    }
    gcd = w/gcd;

    int ans = min/gcd;
    int sum = ((ans)*(ans+1))/2;
    std::cout << min*ans - gcd*sum<< std::endl;
  }

  return 0;
}