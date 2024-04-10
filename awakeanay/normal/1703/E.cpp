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

    char a[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        std::cin >> a[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        std::pair<int, int> p = {i, j};
        std::pair<int, int> q = {n-1-j, i};
        std::pair<int, int> r = {n-1-i, n-1-j};
        std::pair<int, int> s = {j, n-1-i};

        std::pair<int, int> check = std::min(p, q);
        check = std::min(check, r);
        check = std::min(check, s);
        if(check.first == i && check.second == j) {
          int ct[2] = {0, 0};
          ct[a[i][j]-'0']++;
          ct[a[n-1-j][i]-'0']++;
          ct[a[n-1-i][n-1-j]-'0']++;
          ct[a[j][n-1-i]-'0']++;
          ans += std::min(ct[0], ct[1]);
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}