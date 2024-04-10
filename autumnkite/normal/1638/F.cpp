#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> sta;
  std::vector<int> l(n), r(n);
  sta.clear();
  for (int i = 0; i < n; ++i) {
    while (!sta.empty() && a[sta.back()] >= a[i]) {
      sta.pop_back();
    }
    l[i] = sta.empty() ? 0 : sta.back() + 1;
    sta.push_back(i);
  }
  sta.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!sta.empty() && a[sta.back()] >= a[i]) {
      sta.pop_back();
    }
    r[i] = sta.empty() ? n : sta.back();
    sta.push_back(i);
  }

  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    long long L = 0, R = 0;
    for (int j = 0; j < i; ++j) {
      L = std::max(L, a[j] * (std::min(i, r[j]) - l[j]));
    }
    for (int j = i; j < n; ++j) {
      R = std::max(R, a[j] * (r[j] - std::max(i, l[j])));
    }
    ans = std::max(ans, L + R);
  }
  for (int i = 0; i < n; ++i) {
    std::vector<long long> tmp(n);
    tmp[i] = a[i];
    for (int j = i - 1; j >= 0; --j) {
      tmp[j] = std::min(tmp[j + 1], a[j]);
    }
    for (int j = i + 1; j < n; ++j) {
      tmp[j] = std::min(tmp[j - 1], a[j]);
    }
    int k, p;
    long long max;
    k = n - 1, p = r[i], max = 0;
    for (int j = l[i] - 1; j >= 0; --j) {
      while (k >= r[i] && tmp[j] + tmp[k] < a[i]) {
        max = std::max(max, (k - l[i] + 1) * tmp[k]);
        --k;
      }
      ans = std::max(ans, max + (r[i] - j) * tmp[j]);
      ans = std::max(ans, (k - l[i] + 1) * (a[i] - tmp[j]) +
                          (r[i] - j) * tmp[j]);
      while (p < n && tmp[p] >= tmp[j]) {
        ++p;
      }
      ans = std::max(ans, tmp[j] * (p - j) + (a[i] - tmp[j]) * (r[i] - l[i]));
    }
    k = 0, p = l[i] - 1, max = 0;
    for (int j = r[i]; j < n; ++j) {
      while (k < l[i] && tmp[j] + tmp[k] < a[i]) {
        max = std::max(max, (r[i] - k) * tmp[k]);
        ++k;
      }
      ans = std::max(ans, max + (j - l[i] + 1) * tmp[j]);
      ans = std::max(ans, (r[i] - k) * (a[i] - tmp[j]) +
                          (j - l[i] + 1) * tmp[j]);
      while (p >= 0 && tmp[p] >= tmp[j]) {
        --p;
      }
      ans = std::max(ans, tmp[j] * (j - p) + (a[i] - tmp[j]) * (r[i] - l[i]));
    }
  }
  std::cout << ans << "\n";
}