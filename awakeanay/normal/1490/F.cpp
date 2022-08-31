#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> store;
    int id = 1;
    std::vector<int> counts;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(store[x])
        counts[store[x]-1]++;
      else {
        counts.push_back(1);
        store[x] = id++;
      }
    }

    std::sort(counts.begin(), counts.end());
    int m = counts.size();
    int pref[m], suff[m];
    for(int i = 0; i < m; i++) {
      pref[i] = counts[i];
      suff[m-1-i] = counts[m-1-i];
      if(i) {
        pref[i] += pref[i-1];
        suff[m-1-i] += suff[m-i];
      }
    }

    int ans = n;
    for(int i = m-1; i >= 0; i--) {
      ans = std::min(ans, (i ? pref[i-1] : 0) + suff[i]-counts[i]*(m-i));
    }
    std::cout << ans << std::endl;
  }

  return 0;
}