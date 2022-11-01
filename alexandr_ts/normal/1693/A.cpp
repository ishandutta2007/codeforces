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

  void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& e : a) {
      cin >> e;
    }
    if (accumulate(a.begin(), a.end(), 0ll)) {
      cout << "No\n";
      return;
    }

    vector<ll> pref(n);
    pref[0] = a[0];
    bool had = false;
    for (int i = 1; i < n; ++i) {
      pref[i] = pref[i - 1] + a[i];
      if (pref[i - 1] <= 0) {
        had = true;
      }
      if (a[i] > 0 && had) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";


  }

private:

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