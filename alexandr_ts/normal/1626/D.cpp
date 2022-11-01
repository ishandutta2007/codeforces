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
    map<int, int> cnt_by_a;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt_by_a[x]++;
    }

    vector<pair<int, int>> v{cnt_by_a.begin(), cnt_by_a.end()};
    vector<int> pref, suf;
    int ptr_l = 0, ptr_r = (int)v.size() - 1;
    int cnt_l = 0, cnt_r = 0;
    for (int al = 0; (1 << al) <= 2 * n; ++al) {
      while (ptr_l < (int)v.size() && v[ptr_l].second + cnt_l <= (1 << al)) {
        cnt_l += v[ptr_l].second;
        ++ptr_l;
      }
      while (ptr_r >= 0 && v[ptr_r].second + cnt_r <= (1 << al)) {
        cnt_r += v[ptr_r].second;
        --ptr_r;
      }
      pref.push_back(cnt_l);
      suf.push_back(cnt_r);
    }

    int ans = n + 1;

    // for (auto e : pref) cout << e << " ";cout << endl;
    // for (auto e : suf) cout << e << " ";cout << endl;

    for (int i = 0; i < (int)pref.size(); ++i) {
      for (int j = 0; j < (int)suf.size(); ++j) {
        if (pref[i] + suf[j] > n) {
          break;
        }
        if (pref[i] + suf[j] == n) {
          ans = min(ans, (1 << i) - pref[i] + (1 << j) - suf[j] + 1);
        } else {
          int lft = n - pref[i] - suf[j];
          int pw = 1;
          while (pw < lft) pw *= 2;
          ans = min(ans, (1 << i) - pref[i] + (1 << j) - suf[j] + pw - lft);
        }
      }
    }
    cout << ans << endl;
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