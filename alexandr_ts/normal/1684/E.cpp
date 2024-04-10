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
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
    }

    vector<int> used(n + 1);
    for (int i = 0; i <= n; ++i) {
      if (cnt.count(i)) {
        used[i] = true;
      }
    }

    int mex = n;
    int cnt_empty = 0;
    for (int i = 0; i <= n; ++i) {
      if (!used[i]) {
        cnt_empty++;
      }
      if (cnt_empty == k + 1) {
        mex = i;
        break;
      }
    }

    if (mex == n) {
      cout << 0 << "\n";
      return;
    }

    vector<int> cnts;
    for (auto [num, c] : cnt) {
      if (num > mex) {
        cnts.push_back(c);
      }
    }
    sort(cnts.begin(), cnts.end());

    int cnt_diss = 0;
    for (auto c : cnts) {
      if (c <= k) {
        k -= c;
        cnt_diss++;
      }
    }

    int diff = mex + (int)cnts.size() - cnt_diss;
    cout << diff - mex << "\n";

  }

private:
  vector<int> a;
  map<int, int> cnt;

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