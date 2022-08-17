#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> type(2*n, 0);
    for(int i = 0; i < l; i++) {
      int x;
      std::cin >> x;
      x--;
      type[x]++;
    }

    for(int i = 0; i < r; i++) {
      int x;
      std::cin >> x;
      x--;
      type[x+n]++;
    }

    int ans = n;
    for(int i = 0; i < n; i++) {
      int cur = std::min(type[i], type[i+n]);
      ans -= 2*cur;
      type[i] -= cur;
      type[i+n] -= cur;
    }

    int lc = 0, rc = 0;
    std::vector<int> lv, rv;
    for(int i = 0; i < 2*n; i++) {
      if(i < n) {
        lc += type[i];
        lv.push_back(type[i]);
      }
      else {
        rc += type[i];
        rv.push_back(type[i]);
      }
    }

    if(lc < rc) {
      rc ^= lc ^= rc ^= lc;
      std::vector<int> tp = lv;
      lv = rv;
      rv = tp;
    }

    int rem = lc-rc;
    ans -= rc;
    std::sort(lv.begin(), lv.end());
    std::reverse(lv.begin(), lv.end());

    for(int i = 0; i < lv.size(); i++) {
      int take = std::min(rem, lv[i]-lv[i]%2);
      rem -= take;
      lv[i] -= take;
      ans -= take/2;
    }
    for(int i = 0; i < lv.size(); i++) {
      int take = std::min(rem, lv[i]);
      rem -= take;
      lv[i] -= take;
      ans -= take/2;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}