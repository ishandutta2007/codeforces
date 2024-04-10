#include <iostream>
#include <set>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> b(n+1, 0);
    int ch = 0;
    std::set<int> st;
    std::vector<int> rem(n+1, 1);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(1 <= x && x <= n && !st.count(x)) {
        st.insert(x);
        rem[x] = 0;
      }
      else {
        x = (x-1)/2;
        b[std::min(n, x)]++;
      }
    }

    int avail = 0;
    bool poss = true;
    for(int i = n; i >= 1; i--) {
      avail += b[i];
      if(avail < rem[i])
        poss = false;
      avail -= rem[i];
    }

    std::cout << (poss ? n-st.size() : -1) << std::endl;
  }

  return 0;
}