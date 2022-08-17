#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::multiset<int> a, b;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a.insert(x);
    }
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      b.insert(x);
    }

    bool poss = true;
    while(a.size()) {
      int u = *a.rbegin();
      int v = *b.rbegin();

      if(u > v) {
        if(u%2 != 0) {
          poss = false;
          break;
        }
        a.erase(a.find(u));
        a.insert(u/2);
      }
      else if(u < v) {
        b.erase(b.find(v));
        b.insert(v/2);
      }
      else {
        a.erase(a.find(u));
        b.erase(b.find(v));
      }
    }

    std::cout << (poss ? "YES" : "NO") << "\n";
  }

  return 0;
}