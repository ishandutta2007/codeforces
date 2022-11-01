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
    a.resize(n);
    map<int, int> cnt_ev;
    for (auto& e : a) {
      cin >> e;
      cnt_ev[e]++;
    }

    for (auto [k, v] : cnt_ev) {
      if (v % 2) {
        cout << "-1\n";
        return;
      }
    }

    int l = 0;
    while (l < (int)a.size()) {
      int r = l + 1;
      while (a[r] != a[l]) {
        r++;
        assert(r < a.size());
      }
      for (int i = l + 1; i < r; ++i) {
        //cout << r + 1 + (i - (l + 1)) << " " << a[i] << "\n";
        ans.push_back({r + 1 + (i - (l + 1)), a[i]});
      }
      vector<int> tmp;
      tmp.reserve(2 * (r - l - 1));
      for (int i = l + 1; i < r; ++i) {
        tmp.push_back(a[i]);
      }
      for (int i = r - 1; i >= l + 1; --i) {
        tmp.push_back(a[i]);
      }
      for (int i = r + 1; i < (int)a.size(); ++i) {
        tmp.push_back(a[i]);
      }
      a.resize(tmp.size() + r + 1);
      for (int i = r + 1; i < (int)tmp.size() + r + 1; ++i) {
        a[i] = tmp[i - (r + 1)];
      }
      ans_t.push_back(r - l);
      l += 2 * (r - l);
    }

    cout << ans.size() << "\n";
    for (auto [x, y]: ans) {
      cout << x << " " << y << "\n";
    }

    cout << ans_t.size() << "\n";
    for (auto x : ans_t) {
      cout << 2 * x << " ";
    }
    cout << "\n";
  }

private:
  vector<int> a;
  vector<int> ans_t;
  vector<pair<int, int>> ans;

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