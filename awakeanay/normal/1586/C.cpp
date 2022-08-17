#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> type(m, 0);
  std::string s[n];
  for(int i = 0; i < n; i++) {
    std::cin >> s[i];
    for(int j = 0; j < m; j++) {
      if(i && j && s[i-1][j] == 'X' && s[i][j-1] == 'X')
        type[j] = 1;
    }
  }

  for(int i = 1; i < m; i++)
    type[i] += type[i-1];
    
  int q;
  std::cin >> q;

  while(q--) {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    int cur = type[y]-type[x];
    std::cout << (cur ? "NO" : "YES") << std::endl;
  }

  return 0;
}