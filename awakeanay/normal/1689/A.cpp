#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string s, t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    int i = 0, j = 0;
    int last = 0, ct = 0;
    std::string out;
    while(true) {
      if(i == n || j == m)
        break;
      if(ct == k) {
        ct = 0;
        out += (last ? s[i++] : t[j++]);
        last ^= 1;
      }
      else {
        if(s[i] < t[j]) {
          out += s[i++];
          if(last == 1) {
            last = 0;
            ct = 0;
          }
        }
        else {
          out += t[j++];
          if(last == 0) {
            last = 1;
            ct = 0;
          }
        }
      }
      ct++;
    }

    std::cout << out << std::endl;
  }

  return 0;
}