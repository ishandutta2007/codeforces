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

    int a[n];
    int pr[n]; 
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      pr[i] = a[i];
      if(i)
        pr[i] += pr[i-1];
    }

    std::sort(a, a+n);

    int tot = 0;
    int x = (n%2 ? n/2+1 : n/2);
    int y = (n%2 ? n/2 : n/2-1);
    
    for(int j = 0; j < x; j++)
      tot -= a[j];
    for(int j = 0; j < y; j++)
      tot += a[n-1-j];

    std::cout << (tot > 0 ? "YES" : "NO") << std::endl;
  }

  return 0;
}