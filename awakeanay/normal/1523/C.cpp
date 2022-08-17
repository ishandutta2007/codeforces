#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;

      if(x == 1) {
        ans[++top] = 1;
      }
      else {
        while(ans[top]+1 != x)
          top--;
        ans[top]++;
      }

      for(int j = 0; j < top; j++)
        std::cout << ans[j] << ".";
      std::cout << ans[top] << std::endl;
    }
  }

  return 0;
}