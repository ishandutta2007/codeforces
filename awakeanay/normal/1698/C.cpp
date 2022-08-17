#include <iostream>
#include <vector>
#include <set>

#define int long long

int type(int x) {
  if(x < 0)
    return 2;
  if(x == 0)
    return 0;
  return 1;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::set<int> avail;
    std::vector<int> count(3, 0);
    std::vector<int> b;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      int tp = type(x);
      count[tp]++;
      if(count[tp] <= 3) {
        b.push_back(x);
        avail.insert(x);
      }
    }

    int m = b.size();
    bool poss = true;
    for(int i = 0; i < m; i++) {
      for(int j = i+1; j < m; j++) {
        for(int k = j+1; k < m; k++) {
          if(!avail.count(b[i] + b[j] + b[k]))
            poss = false;
        }
      }
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}