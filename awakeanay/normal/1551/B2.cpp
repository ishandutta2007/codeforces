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
    std::cin >> n >> k;

    int a[n];
    int count = 0;
    std::set<int> dist;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      pos[a[i]].push_back(i);
      dist.insert(a[i]);
    }

    for(int j : dist) {
      count += std::min(k, (int)pos[j].size());
    }

    int ans = count/k;
    ans *= k;
    ans--;

    std::vector<int> out(n, 0);

    for(int j : dist) {
      for(int i = 0; i < pos[j].size() && i < k && ans >= 0; i++) {
        out[pos[j][i]] = (ans%k)+1;
        ans--;
      }
      pos[j].clear();
    }

    for(int j : out)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}