#include <iostream>
#include <set>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int a[m], b[m];
  for(int i = 0; i < m; i++)
    std::cin >> a[i] >> b[i];

  bool poss = false;
  for(int u = 0; u < 2; u++) {
    int x = a[0];
    int cur = -1;
    std::set<int> inter;
    for(int i = 1; i < m; i++) {
      if(a[i] == x || b[i] == x)
        continue;
      std::set<int> st = {a[i], b[i]};
      if(cur == -1) {
        inter = st;
        cur = 1;
      }
      else {
        std::set<int> ninter;
        for(int j : inter) {
          if(st.count(j))
            ninter.insert(j);
        }
        inter = ninter;
      }
    }

    if(cur == -1 || inter.size())
      poss = 1;

    a[0] ^= b[0] ^= a[0] ^= b[0];
  }

  std::cout << (poss ? "YES" : "NO") << std::endl;

  return 0;
}