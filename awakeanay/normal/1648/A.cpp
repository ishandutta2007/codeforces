#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::map<int, int> mp;

  int c[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cin >> c[i][j];
      mp[c[i][j]]++;
    }
  }

  std::map<int, int> mpc;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int u = mpc[c[i][j]];
      ans += u*i;
      mpc[c[i][j]]++;
      ans -= (mp[c[i][j]]-u-1)*i;
    }
  }

  mpc.clear();
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      int u = mpc[c[j][i]];
      ans += u*i;
      mpc[c[j][i]]++;
      ans -= (mp[c[j][i]]-u-1)*i;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}