#include <iostream>
#include <iomanip>

int a[100006];

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, max;
    std::cin >> n >> max;

    int a[n+2];
    a[0] = 0;
    for(int i = 0; i < n; i++)
      std::cin >> a[i+1];
    a[n+1] = max;

    long double l = 0.0, r = max;
    while((r-l) > 1e-6) {
      long double m = (l+r)/((long double) 2.0);
      long double curt = 0.0;
      long double apos = 0.0;
      long double speed = 1.0;
      for(int i = 1; i < n+2; i++) {
        if(apos + (m-curt)*speed >= a[i]) {
          apos = a[i];
          curt += ((long double)(a[i]-a[i-1]))/speed;
          speed += 1.0;
        }
        else {
          apos = apos + (m-curt)*speed;
          break;
        }
      }

      speed = 1.0;
      long double bpos = a[n+1];
      curt = 0.0;

      for(int i = n; i >= 0; i--) {
        if(bpos - (m-curt)*speed <= a[i]) {
          bpos = a[i];
          curt += ((long double)(a[i+1]-a[i]))/speed;
          speed += 1.0;
        }
        else {
          bpos = bpos - (m-curt)*speed;
          break;
        }
      }

      if(apos < bpos)
        l = m;
      else
        r = m;
    }
    
    std::cout << std::setprecision(15) << l << std::endl;
  }

  return 0;
}