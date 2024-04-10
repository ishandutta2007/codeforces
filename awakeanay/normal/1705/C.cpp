#include <iostream>
#include <set>

#define int long long

const int INF = 2'000'000'000'000'000'000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, c, q;
    std::cin >> n >> c >> q;

    std::string s;
    std::cin >> s;
    std::set<std::pair<int, int> > st;
    st.insert({INF, INF});
    int cur = n;
    for(int i = 0; i < c; i++) {
      int l, r;
      std::cin >> l >> r;
      l--; r--;
      st.insert({cur, l});
      cur += r-l+1;
    }

    while(q--) {
      int k;
      std::cin >> k;
      k--;

      while(k >= n) {
        auto it = st.upper_bound({k, INF});
        it--;
        /*
        std::cout << k << std::endl;
        std::cout << (*it).first << " " << (*it).second << std::endl;
        */
        k = k-(*it).first+(*it).second;
      }

      std::cout << s[k] << "\n";
    }
  }

  return 0;
}