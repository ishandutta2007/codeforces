#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int r, c;
    std::cin >> r >> c;
    r--; c--;

    std::string s[n];
    for(int i = 0; i < n; i++)
      std::cin >> s[i];

    int ans = -1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(s[i][j] == 'B')
          ans = 2;
    for(int i = 0; i < n; i++)
      if(s[i][c] == 'B')
        ans = 1;
    for(int i = 0; i < m; i++)
      if(s[r][i] == 'B')
        ans = 1;

    if(s[r][c] == 'B')
      ans = 0;

    std::cout << ans << std::endl;
  }

  return 0;
}