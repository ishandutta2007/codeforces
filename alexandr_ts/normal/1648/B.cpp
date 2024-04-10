#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  bool solve() {
    ll n, c;
    cin >> n >> c;
    a.resize(n);
    pref.resize(c + 1);
    has.resize(c + 1);
    for (auto& e : a) {
      cin >> e;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      pref[a[i]]++;
      has[a[i]]++;
    }
    for (int i = 1; i <= c; ++i) {
      pref[i] += pref[i - 1];
    }

    for (ll k = 1; k <= c; ++k) {
      if (has[k]) continue;
      for (ll y = 1; y * k <= c; ++y) {
        if (!has[y]) continue;
        ll minx = y * k;
        ll maxx = min(c, y * k + y - 1);
        if (pref[maxx] - pref[minx - 1] > 0) {
          return false;
        }
      }
    }

    return true;

  }

private:
  vector<int> a, pref, has;

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    auto rez = Solver{}.solve();
    if (rez) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}