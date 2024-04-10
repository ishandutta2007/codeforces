#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    int v;
    std::cin >> v;
    if (i > 1) {
      a[i] -= v;
    }
  }

  std::vector<std::pair<long long, long long>> f(n + 1);
  f[1] = std::make_pair(1, -a[1]);
  for (int i = 2; i <= n; ++i) {
    f[i] = std::make_pair(0, -a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + i; j <= n; j += i) {
      f[j].first -= f[i].first;
      f[j].second -= f[i].second;
    }
  }

  long long ans = 0;
  std::vector<long long> p;
  for (int i = 1; i <= n; ++i) {
    if (f[i].first) {
      p.push_back(-f[i].second / f[i].first);
    } else {
      ans += std::abs(f[i].second);
    }
  }
  std::sort(p.begin(), p.end());

  std::vector<long long> sum(p.size() + 1);
  for (int i = 0; i < (int)p.size(); ++i) {
    sum[i + 1] = sum[i] + p[i];
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    std::cin >> x;
    int t = std::lower_bound(p.begin(), p.end(), x) - p.begin();
    std::cout << ans + 1ll * x * t - sum[t] + (sum[p.size()] - sum[t])
                     - 1ll * x * ((int)p.size() - t) << "\n";
  }
}