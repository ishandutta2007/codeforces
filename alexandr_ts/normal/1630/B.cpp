#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    auto b = a;

    sort(a.begin(), a.end());
    int best_x = -INF, best_y = INF;
    for (int i = 0; i < n; ++i) {
      int j = (k + n + 1) / 2 + i - 1;
      if (j >= n) break;
      if (a[j] - a[i] < best_y - best_x) {
        best_x = a[i];
        best_y = a[j];
      }
    }

    cout << best_x << " " << best_y << "\n";
    vector<int> segs;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
      if (best_x <= b[i] && b[i] <= best_y) {
        ++bal;
      } else {
        --bal;
      }
      if (bal == 1 && (int)segs.size() < k) {
        segs.push_back(i);
        bal = 0;
      }
    }
    segs.back() = n - 1;
    assert((int)segs.size() == k);
    for (int i = 0; i < k; ++i) {
      int l = 0;
      if (i) {
        l = segs[i - 1] + 1;
      }
      cout << l + 1 << " " << segs[i] + 1 << "\n";
    }
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