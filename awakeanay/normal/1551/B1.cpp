#include <iostream>
#include <vector>
#include <set>

#define int long long

const int MAXN = 200005;

std::vector<int> pos[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::string s;
    std::cin >> s;
    k = 2;

    n = s.length();

    int a[n];
    int count = 0;
    std::set<int> dist;
    for(int i = 0; i < n; i++) {
      a[i] = s[i]-'a';
      pos[a[i]].push_back(i);
      dist.insert(a[i]);
    }

    for(int j : dist) {
      count += std::min(k, (int)pos[j].size());
      pos[j].clear();
    }

    int ans = count/k;
    std::cout << ans << std::endl;

  }

  return 0;
}