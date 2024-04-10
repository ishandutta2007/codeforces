#include <iostream>

#define int long long

int range(int a, int b) {
  if(b < a)
    return 0;
  return b-a+1;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = 0;
    int c = 3;
    while((c*c)/2 + 1 <= n) {
      ans++;
      c += 2;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}