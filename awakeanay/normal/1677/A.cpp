#include <iostream>
#include <vector>

#define int long long

int suff[5005][5005];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> pref;
    int p[n+1];
    for(int i = 1; i <= n; i++) {
      std::cin >> p[i];
      p[i]--;
    }

    pref = std::vector<int>(n, 0);

    for(int i = 0; i < n; i++)
      suff[n+1][i] = 0;
    for(int i = n; i >= 1; i--) {
      for(int j = n-1; j >= 0; j--)
        suff[i][j] = suff[i+1][j] + (j > p[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = n; j > i; j--) {
        ans += pref[p[j]]*suff[j+1][p[i]];
      }
      for(int j = n-1; j > p[i]; j--)
        pref[j]++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}