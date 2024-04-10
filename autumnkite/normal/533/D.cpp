#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> x(n + 2);
  for (int i = 0; i <= n + 1; ++i) {
    std::cin >> x[i];
  }
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] *= 2;
    a[i] = std::min(a[i], x[n + 1]);
  }
  a[0] = a[n + 1] = x[n + 1];

  std::vector<int> l(n + 2), r(n + 2);
  std::vector<int> sta;
  sta.push_back(0);
  for (int i = 1; i <= n + 1; ++i) {
    while (!sta.empty() && a[sta.back()] < x[i] - x[l[sta.back()]]) {
      sta.pop_back();
    }
    l[i] = sta.back();
    sta.push_back(i);
  }
  if ((int)sta.size() > 2) {
    std::cout << 0 << "\n";
    return 0;
  }
  sta.clear();
  sta.push_back(n + 1);
  r[n + 1] = n + 1;
  for (int i = n; i >= 0; --i) {
    while (!sta.empty() && a[sta.back()] < x[r[sta.back()]] - x[i]) {
      sta.pop_back();
    }
    r[i] = sta.back();
    sta.push_back(i);
  }

  int ans = x[n + 1];

  sta.clear();
  sta.push_back(0);
  for (int i = 1; i <= n; ++i) {
    int p = x[r[i]] - a[i];
    if (p < x[i]) {
      int j = *--std::upper_bound(sta.begin(), sta.end(), p, [&](int v, int j) {
        return a[j] + x[l[j]] < v;
      });
      ans = std::min(ans, x[i] - x[j]);
    }
    if (x[i] - x[l[i]] < a[i]) {
      while (!sta.empty() && a[sta.back()] + x[l[sta.back()]] <= a[i] + x[l[i]]) {
        sta.pop_back();
      }
      sta.push_back(i);
    }
  }

  sta.clear();
  sta.push_back(n + 1);
  for (int i = n; i >= 1; --i) {
    int p = x[l[i]] + a[i];
    if (p > x[i]) {
      int j = *--std::upper_bound(sta.begin(), sta.end(), p, [&](int v, int j) {
        return x[r[j]] - a[j] > v;
      });
      ans = std::min(ans, x[j] - x[i]);
    }
    if (x[r[i]] - x[i] < a[i]) {
      while (!sta.empty() && x[r[sta.back()]] - a[sta.back()] >= x[r[i]] - a[i]) {
        sta.pop_back();
      }
      sta.push_back(i);
    }
  }
  if (ans & 1) {
    std::cout << ans / 2 << ".5\n";
  } else {
    std::cout << ans / 2 << "\n";
  }
}