#include <iostream>
#include <vector>

#define int long long

signed main() {
  int k;
  std::cin >> k;

  std::string s = "codeforces";
  int n = s.length();

  std::vector<int> count(n, 1);
  int ans = 1;
  int id = 0;

  while(ans < k) {
    int cur = id%n;
    ans /= count[cur];
    count[cur]++;
    ans *= count[cur];
    id++;
  }

  for(int i = 0; i < n; i++) {
    while(count[i]) {
      std::cout << s[i];
      count[i]--;
    }
  }

  std::cout << std::endl;
  return 0;
}