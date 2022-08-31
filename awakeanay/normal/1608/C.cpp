#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::pair<int, int> hpa[n], hpb[n];
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
      std::cin >> hpa[i].first;
      hpa[i].second = i;
      a[i] = hpa[i].first;
    }

    int ans[n];
    for(int i = 0; i < n; i++) {
      ans[i] = 0;
      std::cin >> b[i];
      hpb[i].first = b[i];
      hpb[i].second = i;
    }

    int max = 0;
    std::sort(hpa, hpa+n);
    std::sort(hpb, hpb+n);

    int awin = n-1, bwin = n-1;
    int acur = n, bcur = n;

    while(awin != acur || bwin != bcur) {
      while(awin < acur) {
        acur--;
        ans[hpa[acur].second] = 1;
        std::pair<int, int> u = {b[hpa[acur].second], -1};
        int it = std::lower_bound(hpb, hpb+n, u)-hpb;
        bwin = std::min(bwin, it);
      }

      while(bwin < bcur) {
        bcur--;
        ans[hpb[bcur].second] = 1;
        std::pair<int, int> u = {a[hpb[bcur].second], -1};
        int it = std::lower_bound(hpa, hpa+n, u)-hpa;
        awin = std::min(awin, it);
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << ans[i];
    std::cout << std::endl;
  }

  return 0;
}