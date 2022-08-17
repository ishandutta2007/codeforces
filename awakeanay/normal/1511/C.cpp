#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> pos(51, n+1);

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    pos[x] = std::min(i+1, pos[x]);
  }

  for(int i = 0; i < q; i++) {
    int x;
    std::cin >> x;

    std::cout << pos[x] << " ";
    for(int j = 1; j <= 50; j++)
      if(pos[j] < pos[x])
        pos[j]++;

    pos[x] = 1;
  }

  std::cout << std::endl;

  return 0;
}