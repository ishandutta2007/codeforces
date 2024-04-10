#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int K = 200;
const int M = 1e5 / K + 2;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto& e : a) {
      cin >> e;
    }

    if (n <= 2) {
      cout << 0 << "\n";
      return;
    }

    ll ans_1 = calc_small(n);
    ll ans_2 = calc_big(n);
    cout << min(ans_1, ans_2) << endl;
  }

private:
  vector<int> a;

  ll calc_small(int n) {
    int ans = n;
    vector<ll> best_a0;
    best_a0.reserve(n);
    for (ll k = -M; k <= M; ++k) {
      best_a0.clear();
      for (ll i = 0; i < n; ++i) {
        best_a0.push_back(a[i] - i * k);
      }
      sort(best_a0.begin(), best_a0.end());
      int mx = 0;
      int cur = 1;
      while (!best_a0.empty()) {
        while (best_a0.size() >= 2 && best_a0.back() == best_a0[(int)best_a0.size() - 2]) {
          cur++;
          best_a0.pop_back();
        }
        mx = max(mx, cur);
        cur = 1;
        best_a0.pop_back();
      }
      ans = min(ans, n - mx);
    }
    return ans;
  }

  ll calc_big(int n) {
    int ans = n - 1;
    for (int l = 0; l < n; ++l) {
      for (int m = l + 1; m < min(n, l + K); ++m) {
        if ((a[m] - a[l]) % (m - l)) continue;
        ll k = (a[m] - a[l]) / (m - l);
        ll to_ad = (m - l) * k;
        int cnt = 1;
        for (int i = m; i < min(n, l + K); ++i) {
          cnt += (a[i] == a[l] + to_ad);
          to_ad += k;
        }
        ans = min(ans, n - cnt);
      }
    }
    return ans;
  }


};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  /*
  cout << 100000 << endl;
  mt19937 g;
  for (int i = 0; i < 100000; ++i) {
    cout << 1 << " ";
  }
  */

  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}