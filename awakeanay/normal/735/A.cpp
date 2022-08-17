#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  std::set<char> st[k];

  bool poss = false;
  for(int i = 0; i < n; i++) {
    int j = i%k;
    char c;
    std::cin >> c;
    st[j].insert(c);
    if(c == '#')
      st[j].clear();
    if(st[j].count('G') && st[j].count('T'))
      poss = true;
  }

  std::cout << (poss ? "YES" : "NO") << std::endl;

  return 0;
}