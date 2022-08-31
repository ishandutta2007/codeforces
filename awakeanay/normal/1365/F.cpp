#include <iostream>
#include <algorithm>

#define int long long

signed main() {
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

    std::pair<int, int> asets[n], bsets[n];
    for(int i = 0; i < n; i++) {
      asets[i] = {a[i], a[n-1-i]};
      bsets[i] = {b[i], b[n-1-i]};
    }

    std::sort(asets, asets+n);
    std::sort(bsets, bsets+n);

    bool poss = true;
    for(int i = 0; i < n; i++) {
      if(asets[i] != bsets[i])
        poss = false;
    }

    if(poss)
      std::cout << "Yes";
    else
      std::cout << "No";
    
    std::cout << std::endl;
  }

  return 0;
}