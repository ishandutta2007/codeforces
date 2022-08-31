#include <iostream>
#include <vector>
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

    int a[n];
    std::set<int> st[n+2];

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      st[a[i]].insert(i);
    }

    int ct = 0;
    std::vector<int> b;
    while(ct < n) {
      int nt = ct;

      int next = -1;
      for(int j = 0; j <= n+1; j++) {
        if(st[j].empty()) {
          next = j;
          break;
        }

        nt = std::max(nt, *st[j].begin());
      }

      for(int i = ct; i <= nt; i++) {
        st[a[i]].erase(i);
      }

      ct = nt+1;
      b.push_back(next);
    }

    std::cout << b.size() << std::endl;
    for(int j : b)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}