#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, v, t[N], a[N];
vector<tuple<ll, ll, int>> A;
vector<ll> B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> v;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    A.emplace_back(1LL * v * t[i] - a[i], 1LL * v * t[i] + a[i], i);
  }
  sort(A.begin(), A.end());
  for (auto [x, y, i] : A) {
    if (B.empty() || y >= B.back()) {
      if (!B.empty() || 1LL * v * t[i] >= (ll)abs(a[i])) {
        B.emplace_back(y);
      }
    } else {
      auto it = upper_bound(B.begin(), B.end(), y);
      if (it != B.begin() || 1LL * v * t[i] >= (ll)abs(a[i])) {
        B[it - B.begin()] = y;
      }
    }
  }
  cout << B.size() << '\n';

  return 0;
}