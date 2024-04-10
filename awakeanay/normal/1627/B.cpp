#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

int dist(int x, int y, int a, int b) {
  return abso(x-a) + abso(y-b);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> ans;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.push_back(std::max(std::max(dist(i, j, 0, 0), dist(i, j, n-1, m-1)), std::max(dist(i, j, 0, m-1), dist(i, j, n-1, 0))));
      }
    }

    std::sort(ans.begin(), ans.end());
    for(int j : ans)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}