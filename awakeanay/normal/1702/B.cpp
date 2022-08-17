#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    std::string s;
    std::cin >> s;

    int ans = 0;
    int n = s.length();
    int cur = 0;

    while(cur < n) {
      std::set<char> st;
      while(cur < n && st.size() <= 3) {
        st.insert(s[cur]);
        if(st.size() == 4) {
          cur--;
        }
        cur++;
      }
      ans++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}