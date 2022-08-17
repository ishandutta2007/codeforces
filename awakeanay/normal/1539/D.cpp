#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::pair<int, int> seq[n];
  int rem = 0;
  int pur = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i].second >> seq[i].first;
    rem += seq[i].second;
  }

  std::sort(seq, seq+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(pur < seq[i].first) {
      int now = std::min(rem, seq[i].first-pur);
      ans += now*2;
      pur += now;
      rem -= now;
    }
    int now = std::min(rem, seq[i].second);
    ans += now;
    pur += now;
    rem -= now;
  }

  std::cout << ans << std::endl;

  return 0;
}