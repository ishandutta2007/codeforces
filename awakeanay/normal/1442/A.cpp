#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    bool poss = true;
    int min = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] - min < 0) {
        poss = false;
      }

      if(a[i] - min > a[i-1]) {
        min += a[i]-min-a[i-1];
        a[i] = a[i-1];
      }
      else {
        a[i] = a[i]-min;
      }
    }

    int minl[n], minr[n];
    int needl[n], needr[n];
    for(int i = 0; i < n; i++) {
      minl[i] = a[i];
      minr[n-1-i] = a[n-1-i];
      if(i) {
        minl[i] = std::min(minl[i], minl[i-1]);
        minr[n-1-i] = std::min(minr[n-1-i], minr[n-i]);
      }
    }

    for(int i = 0; i < n; i++) {
      needl[i] = a[i]-minr[i];
      needr[i] = a[i]-minl[i];
      if(i)
        needr[i] = std::max(needr[i], needr[i-1]);
    }

    for(int i = n-2; i >= 0; i--) {
      needl[i] = std::max(needl[i], needl[i+1]);
    }

    for(int i = 0; i < n; i++) {
      int need = 0;
      if(i+1 < n)
        need += needl[i+1];
      if(i)
        need += needr[i-1];
    }

    if(poss)
      std::cout << "YES";
    else
      std::cout << "NO";
    std::cout << std::endl;
  }
  
  return 0;
}