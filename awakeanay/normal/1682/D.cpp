#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int val[n];
    for(int i = 0; i < n; i++)
      val[i] = i;

    int one = 0;
    int x = 0;
    for(int i = 0; i < n; i++) {
      one |= s[i] == '1';
      x ^= s[i] == '1';
    }

    if(x == 0 && one) {
      std::cout << "YES" << std::endl;
      for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
          int rot = (i+1)%n;
          std::rotate(val, val+rot, val+n);
          std::rotate(s.begin(), s.begin()+rot, s.end());
          break;
        }
      }

      int j = 1;
      while(j < n) {
        std::cout << val[0]+1 << " " << val[j]+1 << std::endl;
        while(s[j] != '1') {
          std::cout << val[j]+1 << " " << val[j+1]+1 << std::endl;
          j++;
        }
        j++;
      }
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}