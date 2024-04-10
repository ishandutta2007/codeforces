#include <iostream>

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

    int i = (n/2);
    int ct = 1;
    int j = i+1;
    while(j < n && s[j] == s[i]) {
      j++;
      ct++;
    }

    j = i-1;
    while(j >= 0 && s[j] == s[i]) {
      j--;
      ct++;
    }

    std::cout << ct << std::endl;
  }

  return 0;
}