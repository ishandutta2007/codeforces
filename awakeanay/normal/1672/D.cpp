#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    std::vector<int> mp[n+1];
    std::vector<int> ct(n+1, 0);
    std::vector<int> bt(n+1, 0);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      mp[a[i]].push_back(i);
      ct[a[i]]++;
    }
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    std::vector<std::pair<int, int> > order;
    bool poss = true;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      int id = bt[b[i]];
      bt[b[i]]++;
      if(bt[b[i]] > ct[b[i]]) {
        poss = false;
        break;
      }
      cur++;
      if(i == n-1 || b[i+1] != b[i]) {
        order.push_back({b[i], cur});
        cur = 0;
      }
    }

    std::reverse(order.begin(), order.end());

    int pt = 0;
    std::vector<int> take(n, 0);
    for(int i = n-1; i >= 0; i--) {
      if(pt < order.size() && a[i] == order[pt].first) {
        take[i] = order[pt].second;
        pt++;
      }
    }

    poss &= pt == order.size();

    std::vector<int> nt(n+1, 0);
    for(int i = 0; i < n; i++) {
      nt[a[i]]++;
      poss &= nt[a[i]] >= take[i];
      nt[a[i]] -= take[i];
    }


    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}