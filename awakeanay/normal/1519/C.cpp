#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> uni[n];
    int u[n], s[n];
    for(int i = 0; i < n; i++)
      std::cin >> u[i];
    for(int i = 0; i < n; i++)
      std::cin >> s[i];

    for(int i = 0; i < n; i++)
      uni[u[i]-1].push_back(s[i]);

    for(int i = 0; i < n; i++) {
      std::sort(uni[i].begin(), uni[i].end());
      std::reverse(uni[i].begin(), uni[i].end());
    }

    for(int i = 0; i < n; i++) {
      for(int j = 1; j < uni[i].size(); j++) {
        uni[i][j] += uni[i][j-1];
      }
    }

    std::set<int> poss;
    for(int i = 0; i < n; i++) {
      if(uni[i].size() > 0)
        poss.insert(i);
    }

    for(int k = 1; k <= n; k++) {
      int cur = 0;
      std::vector<int> toer;
      for(int i : poss) {
        int j = uni[i].size();
        if(j == k)
          toer.push_back(i);
        j -= j%k;
        cur += uni[i][j-1];
      }

      std::cout << cur << " ";
      for(int j : toer)
        poss.erase(j);
    }

    std::cout << std::endl;
  }

  return 0;
}