#include <iostream>
#include <map>
#include <vector>

std::pair<int, int> operator+(std::pair<int, int> a, std::pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    std::pair<int, int> val[n], pref[n], sol[n];
    std::pair<int, int> cur = {n, n};

    for(int i = 0; i < n; i++) {
      if(s[i] == 'U')
        val[i] = {0, 1};
      else if(s[i] == 'D')
        val[i] = {0, -1};
      else if(s[i] == 'L')
        val[i] = {-1, 0};
      else
        val[i] = {1, 0};
      pref[i] = cur = cur + val[i];
    }

    for(int i = n-1; i >= 0; i--) {
      sol[i] = val[i];
      for(int j = i+1; j < n; j++) {
        if(pref[i] + val[i] == pref[j]) {
          sol[i] = sol[i] + sol[j];
          break;
        }
      }
    }

    std::map<std::pair<int, int>, int> done;
    done[{n, n}] = 1;

    std::pair<int, int> ans = {n, n};
    for(int i = 0; i < n; i++) {
      if(!done[pref[i]]) {
        if((std::pair<int, int>) {n, n} + sol[i] == pref[n-1])
          ans = pref[i];
        done[pref[i]] = 1;
      }
    }

    std::cout << ans.first-n << " " << ans.second-n << std::endl;
  }

  return 0;
}