#include <bits/stdc++.h>

#define int long long

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> w(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    sum += a;
    w[i] = b - a;
  }
  std::sort(w.begin(), w.end(), std::greater<int>());
  std::vector<long long> pre(n + 1);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + w[i];
  }

  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    int x, y;
    int g = exgcd(a, b, x, y);
    if (n % g != 0) {
      std::cout << -1 << "\n";
      continue;
    }
    a /= g, b /= g;
    x = (1ll * x * (n / g) % b + b) % b;
    y = (n / g - 1ll * a * x) / b;
    if (y < 0) {
      std::cout << -1 << "\n";
      continue;
    }
    int l = 0, r = y / a + 1;
    auto calc = [&](int t) {
      return pre[b * g * (y - a * t)];
    };
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (calc(mid - 1) < calc(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    std::cout << sum + calc(l) << "\n";
  }
}