#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, t;
  std::cin >> n >> t;
  std::vector<int> s(n + 1);
  s[n] = t;
  for (int i = n - 1; i > 0; --i) {
    auto do_op = [&]() {
      std::cout << "? 1 " << i << std::endl;
      int x;
      std::cin >> x;
      return x;
    };
    s[i] = t - (n - t) + i;
    for (int j = 0; j < 30; j += 2) {
      int a = do_op();
      int b = do_op();
      if (a != n - t) {
        s[i] = t - a + i;
        t = b;
        break;
      }
      if (b != t) {
        s[i] = t - (n - b) + i;
        t = b;
        break;
      }
    }
    s[i] /= 2;
  }
  std::cout << "! ";
  for (int i = 0; i < n; ++i) {
    std::cout << s[i + 1] - s[i];
  }
  std::cout << std::endl;
}