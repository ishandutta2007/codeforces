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

  int f(int l, int r, int lvl) {
      //cout << l << "-" << r << endl;
    if (l + 1 == r) {
      //cout << l << " " << r << endl;
      return 1;
    }
    if (l >= r) return 0;
    auto j = lower_bound(ls[lvl].begin(), ls[lvl].end(), l) - ls[lvl].begin();

    int ans = 1;
    for (int i = j; i < (int)ls[lvl].size() && ls[lvl][i] <= r; i += 2) {
      ans += f(ls[lvl][i] + 1, ls[lvl][i + 1] - 1, lvl + 1);
    }
      //cout << l << " " << r << " " << ans << endl;
    return ans;
  }

  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    ls.resize(n + 1);
    for (int i = 0; i < 2 * n; ++i) {
      if (s[i] == '(') {
        ls[bal].push_back(i);
        bal++;
      } else {
        bal--;
        ls[bal].push_back(i);
      }
    }

    cout << f(0, 2 * n - 1, 0) << "\n";
  }

private:
  vector<vector<int>> ls;

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