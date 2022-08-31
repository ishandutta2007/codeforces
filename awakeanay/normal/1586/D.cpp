#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> next(n, -1);
  std::vector<int> prev(n, -1);

  for(int i = n-1; i >= 0; i--) {
    std::cout << "? ";
    for(int j = 0; j < n; j++)
      std::cout << (i == j ? "1" : "2") << " ";
    std::cout << std::endl;
    int x;
    std::cin >> x;
    if(x != 0 && x != i+1) {
      next[x-1] = i;
      prev[i] = x-1;
    }
  }

  for(int i = n-1; i >= 0; i--) {
    std::cout << "? ";
    for(int j = 0; j < n; j++)
      std::cout << (i == j ? "2" : "1") << " ";
    std::cout << std::endl;
    int x;
    std::cin >> x;
    if(x != 0 && x != i+1) {
      next[i] = x-1;
      prev[x-1] = i;
    }
  }

  int first = -1;
  int ans[n];
  for(int i = 0; i < n; i++) {
    if(prev[i] == -1) {
      ans[i] = 1;
      first = i;
    }
  }

  int cur = first;
  for(int i = 0; i < n; i++) {
    ans[cur] = i+1;
    cur = next[cur];
  }

  std::cout << "! ";
  for(int i = 0; i < n; i++)
    std::cout << ans[i] << " ";
  std::cout << std::endl;

  return 0;
}