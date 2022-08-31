#include <iostream>
#include <vector>

#define int long long

int query(int x, int y, int z) {
  std::cout << "? " << x+1 << " " << y+1 << " " << z+1 << std::endl;
  int ret;
  std::cin >> ret;
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int last = query(0, 1, 2);
    int a[n];
    int x, y;
    for(int i = 1; i+3 <= n; i++) {
      int cur = query(i, i+1, i+2);
      if(cur != last) {
        x = i-1;
        y = i+2;
        a[x] = last;
        a[y] = cur;
        break;
      }
    }

    for(int i = 0; i < n; i++) {
      if(i == x || i == y)
        continue;
      a[i] = query(i, x, y);
    }

    std::vector<int> ans;
    for(int i = 0; i < n; i++)
      if(!a[i])
        ans.push_back(i);

    std::cout << "! " << ans.size() << " ";
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}