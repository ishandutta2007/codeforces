#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), p(n), x(m);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    a[i] = 200 * i;
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i];
    x[i] *= 2;
  }
  sort(x.begin(), x.end());
  vector<int> d(n, 1'000'000'000);
  map<int, vector<ll>> evs;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
    for (int di = -2; di <= 2; di++) {
      int j = pos + di;
      if (0 <= j && j < m) {
        d[i] = min(d[i], abs(a[i] - x[j]));
      }
    }

    if (d[i] > 0) {
      evs[a[i] - d[i] + 1].push_back(p[i]);
      evs[a[i] + d[i] - 1].push_back(-p[i]);
    }
  }

  ll res = 0;
  ll sum = 0;
  for (auto[i, add]: evs) {
    sort(add.rbegin(), add.rend());
    for (ll s: add) {
      sum += s;
      res = max(res, sum);
    }
  }
  cout << res;
  return 0;
}