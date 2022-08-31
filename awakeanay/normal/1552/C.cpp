#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> mark(2*n, -2);
    std::vector<std::pair<int, int> > output;

    for(int i = 0; i < k; i++) {
      int x, y;
      std::cin >> x >> y;
      x--; y--;
      if(x > y)
        x ^= y ^= x ^= y;
      mark[x] = -1;
      mark[y] = x;
      output.push_back({x, y});
    }


    std::vector<int> rem;
    for(int i = 0; i < 2*n; i++)
      if(mark[i] == -2)
        rem.push_back(i);

    for(int j = 0; j < n-k; j++) {
      mark[rem[j]] = -1;
      mark[rem[j+n-k]] = rem[j];
      output.push_back({rem[j], rem[j+n-k]});
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(output[i].first < output[j].first && output[i].second < output[j].second && output[j].first < output[i].second)
          ans++;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}