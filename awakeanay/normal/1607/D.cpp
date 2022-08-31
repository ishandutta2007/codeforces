#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::vector<int> b, r;
    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      if(c == 'B')
        b.push_back(a[i]);
      else
        r.push_back(a[i]);
    }

    std::sort(b.begin(), b.end());
    std::sort(r.begin(), r.end());

    bool poss = true;
    int cur = 1;
    int done = 0;
    for(int i : b) {
      if(cur <= i) {
        cur++;
        done++;
      }
    }

    std::reverse(r.begin(), r.end());
    cur = n;
    for(int j : r) {
      if(cur >= j) {
        cur--;
        done++;
      }
    }

    std::cout << (done == n ? "YES" : "NO") << std::endl;
  }

  return 0;
}