#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> count[n+1];
  count[0] = std::vector<int>(26, 0);

  std::string s;
  std::cin >> s;

  for(int i = 1; i <= n; i++) {
    count[i] = count[i-1];
    count[i][s[i-1]-'a']++;
  }

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
      ans += (i+1)*(count[r][i] -  count[l][i]);
    }
    std::cout << ans << std::endl;
  }

  return 0;
}