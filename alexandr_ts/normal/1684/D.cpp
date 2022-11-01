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

  ll solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> a(n);
    vector<ll> ar(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      ar[i] = a[i].first;
      a[i].second = i;
      a[i].first -= (n - i - 1);
    }

    sort(a.begin(), a.end(), greater<pair<ll, int>>());
    vector<int> skip(n);
    for (int i = 0; i < k; ++i) {
      skip[a[i].second] = true;
    }

    ll ans = 0;
    ll add = 0;
    for (int i = 0; i < n; ++i) {
      if (skip[i]) {
        add++;
      } else {
        ans += (ar[i] + add);
      }
    }
    return ans;

  }

private:


};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << Solver{}.solve() << "\n";
  }
}