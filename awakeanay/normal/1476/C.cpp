#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
      std::cin >> c[i];
      c[i]--;
    }
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    int cont = -c[0]-2;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      cont += 2;
      ans = std::max(ans, cont + c[i]);

      if(i+1 < n) {
        int abso = a[i+1] > b[i+1] ? a[i+1]-b[i+1] : b[i+1]-a[i+1];
        cont = std::max(cont + c[i] - abso, abso);
        if(a[i+1] == b[i+1])
          cont = 0;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}