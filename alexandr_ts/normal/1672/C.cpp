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
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == a[i + 1]) cnt++;
    }
    if (cnt <= 1) {
      cout << "0\n";
      return;
    }

    int last_i = -1;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] == a[i + 1]) {
        last_i = i - 1;
        break;
      }
    }
    int first_i = -1;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] == a[i + 1]) {
        first_i = i + 1;
        break;
      }
    }
    last_i = max(last_i, first_i);
    cout << last_i - first_i + 1 << "\n";
  }

private:
  vector<vector<vector<int>>> d;

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