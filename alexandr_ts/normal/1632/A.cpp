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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i  + 1 < n; ++i) {
      if (s[i] == s[i + 1]) return true;
    }
    for (int i = 0; i + 2 < n; ++i) {
      if (s[i] == s[i + 2]) return true;
    }
    return false;
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    auto r = Solver{}.solve();
    if (r) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}