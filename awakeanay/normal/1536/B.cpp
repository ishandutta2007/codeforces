#include <iostream>
#include <algorithm>
#include <string>
#include <set>

#define int long long

const int LIM = 15;

std::string next(std::string a) {
  int n = a.length();
  if(a == std::string(n, 'z'))
    return std::string(n+1, 'a');
  for(int i = n-1; i >= 0; i--) {
    if(a[i] != 'z') {
      a[i]++;
      return a;
    }
    a[i] = 'a';
  }
}

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

    std::set<std::string> vec;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < LIM && i+j < n; j++) {
        vec.insert(s.substr(i, j+1));
      }
    }


    std::string cur = "a";
    while(true) {
      if(!vec.count(cur)) {
        std::cout << cur << std::endl;
        break;
      }
      cur = next(cur);
    }
  }

  return 0;
}