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
    string s;
    cin >> s;
    map<char, int> p;
    for (int i = 0; i < (int)s.size(); ++i) {
      p[s[i]] = i;
    }
    int ans = s.size();
    for (auto [_, v] : p) {
      ans = min(ans, v);
    }

    cout << s.substr(ans, (int)s.size() - ans) << "\n";
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