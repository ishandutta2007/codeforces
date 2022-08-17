#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    bool poss = true;

    std::vector<int> a(26, 0), b(26, 0);

    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      a[c-'a']++;
    }

    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      b[c-'a']++;
    }

    int need = 0;
    for(int i = 25; i >= 0; i--) {
      int diff = b[i] - a[i];
      if(diff%k)
        poss = false;

      if(need + diff < 0)
        poss = false;

      need += diff;
    }

    if(need)
      poss = false;

    if(poss)
      std::cout << "Yes";
    else
      std::cout << "No";

    std::cout << std::endl;
  }

  return 0;
}