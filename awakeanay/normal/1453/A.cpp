#include <set>
#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::set<int> st;
    for(int i = 0; i < n+m; i++) {
      int x;
      std::cin >> x;
      st.insert(x);
    }

    std::cout << n+m-st.size() << std::endl;
  }

  return 0;
}