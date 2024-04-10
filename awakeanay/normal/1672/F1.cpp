#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> pos[n];
    int an[n];
    for(int i = 0; i < n; i++) {
      std::cin >> an[i];
      an[i]--;
      pos[an[i]].push_back(i);
    }

    int b[n];
    std::vector<std::pair<int, int> > help;
    for(int j = 0; j < n; j++) {
      help.push_back({pos[j].size(), j});
    }

    std::sort(help.begin(), help.end());

    int ct = 0;
    for(int i = 0; i < n; i++) {
      while(ct < n && help[ct].first <= i)
        ct++;
      if(ct == n)
        break;
      std::vector<int> rot;
      for(int j = ct; j < n; j++) {
        rot.push_back(pos[help[j].second][i]);
      }
      int sz = rot.size();
      for(int j = 0; j < rot.size(); j++) {
        b[rot[j]] = an[rot[(j+1)%sz]];
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << b[i]+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}