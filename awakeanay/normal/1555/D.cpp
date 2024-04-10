#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;

  int pref[3][2][n];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 2; k++) {
        int cur = j + (k+1)*i;
        cur %= 3;
        pref[j][k][i] = 0;

        if(s[i]-'a' != cur)
          pref[j][k][i]++;
        if(i)
          pref[j][k][i] += pref[j][k][i-1];
      }
    }
  }

  while(m--) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;

    int ans = (r-l+1);
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 2; j++) {
        int cur = pref[i][j][r] - (l == 0 ? 0 : pref[i][j][l-1]);
        ans = std::min(ans, cur);
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}