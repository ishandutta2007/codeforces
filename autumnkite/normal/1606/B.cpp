#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long n, k;
    std::cin >> n >> k;
    long long now = 1, ans = 0;
    while (now < k) {
      now += now;
      ++ans;
    }
    if (now < n) {
      ans += (n - now - 1) / k + 1;
    }
    std::cout << ans << "\n";
  }
}