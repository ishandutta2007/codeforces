#include <bits/stdc++.h>

int query(int x) {
  std::cout << "? " << x << std::endl;
  int res;
  std::cin >> res;
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int l = 0, r = 5e6;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (query(mid) == 1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  int ans = r;
  for (int i = 2; i <= n; ++i) {
    int h = query((r - 1) / i);
    if (!h) {
      break;
    }
    if (h == i) {
      ans = std::min(ans, ((r - 1) / i) * h);
    }
  }
  std::cout << "! " << ans << std::endl;
}