#include <iostream>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    bool exist = false;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] == k)
        exist = true;
    }

    bool poss = (a[0] == k && n == 1);

    int pref[n];
    int suff[n];

    for(int i = 0; i < n; i++) {
      pref[i] = (a[i] >= k) ? 1 : -1;
      if(i) pref[i] += pref[i-1];
    }

    for(int i = n-1; i >= 0; i--) {
      suff[i] = pref[i];
      if(i < n-1)
        suff[i] = std::max(suff[i+1], suff[i]);
    }

    for(int i = 0; i < n-1; i++) {
      if(a[i] >= k && suff[i+1]-pref[i] >= 0)
        poss = true;
    }

    std::reverse(a, a+n);

    for(int i = 0; i < n; i++) {
      pref[i] = (a[i] >= k) ? 1 : -1;
      if(i) pref[i] += pref[i-1];
    }

    for(int i = n-1; i >= 0; i--) {
      suff[i] = pref[i];
      if(i < n-1)
        suff[i] = std::max(suff[i+1], suff[i]);
    }

    for(int i = 0; i < n-1; i++) {
      if(a[i] >= k && suff[i+1]-pref[i] >= 0)
        poss = true;
    }

    if(poss && exist)
      std::cout << "yes";
    else
      std::cout << "no";
    std::cout << std::endl;
  }

  return 0;
}