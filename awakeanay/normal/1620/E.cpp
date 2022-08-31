#include <iostream>
#include <vector>

#define int long long

const int MAXN = 500005;

std::vector<int> app[MAXN];
int arr[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ind = 0;
  
  int q;
  std::cin >> q;

  while(q--) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int x;
      std::cin >> x;
      app[x].push_back(ind++);
    }
    else {
      int x, y;
      std::cin >> x >> y;

      if(x == y)
        continue;

      if(app[x].size() > app[y].size()) {
        for(int j : app[y])
          app[x].push_back(j);
        app[y].clear();
        app[x].swap(app[y]);
      }
      else {
        for(int j : app[x])
          app[y].push_back(j);
        app[x].clear();
      }
    }
  }

  for(int i = 0; i < MAXN; i++)
    for(int j : app[i])
      arr[j] = i;

  for(int i = 0; i < ind; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  return 0;
}