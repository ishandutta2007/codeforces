#include <iostream>
#include <vector>
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

    int p[n];
    for(int i = 0; i < n; i++)
      std::cin >> p[i];

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int> > check[2];

    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        check[0].push_back({p[i], i});
      }
      else {
        check[1].push_back({p[i], i});
      }
    }

    int cur = 0;
    std::sort(check[0].begin(), check[0].end());
    std::sort(check[1].begin(), check[1].end());

    int q[n];
    for(int j = 0; j < 2; j++) {
      for(auto i : check[j]) {
        q[i.second] = ++cur;
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << q[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}