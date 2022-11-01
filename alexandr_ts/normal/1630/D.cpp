#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e16;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    ll g = 0;
    for (int i = 0; i < m; ++i) {
      ll x;
      cin >> x;
      g = __gcd(x, g);
    }

    vector<ll> pref(n + 1), suf(n + 1);
    vector<ll> abs_pref(n + 1), abs_suf(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + a[i];
      abs_pref[i + 1] = abs_pref[i] + abs(a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
      suf[i] = suf[i + 1] + a[i];
      abs_suf[i] = abs_suf[i + 1] + abs(a[i]);
    }


    if (g == 1) {
      cout << abs_pref[n] << "\n";
      return;
    }

    vector<vector<int>> gg(g);
    for (int i = 0; i < n; ++i) {
      gg[i % g].push_back(a[i]);
    }

    ll ans1 = 0;
    for (auto& row : gg) {
      ll sum = calc(row);
      ans1 += sum;
    }

    for (auto& r : gg) {
      if (!r.empty()) {
        r[0] *= -1;
      }
    }
    ll ans2 = 0;
    for (auto& row : gg) {
      ll sum = calc(row);
      ans2 += sum;
    }




    cout << max(ans1, ans2) << "\n";
  }

private:
  ll calc(vector<int>& row) {
    sort(row.begin(), row.end());
    ll sum = 0;
    for (int i = 0; i + 1 < (int)row.size(); i += 2) {
      if (row[i] + row[i + 1] < 0) {
        row[i] = -row[i];
        row[i + 1] = -row[i + 1];
      }
    }
    for (auto e : row) {
      sum += e;
    }
    return sum;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solver{}.solve();
  }
}