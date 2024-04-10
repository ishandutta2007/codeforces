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
    if (ok(s)) 
    {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  bool ok(string s) {
    if (s.back() != 'B') return false;

    int cnta = 0, cntb = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == 'B') {
        cntb++;
      } else {
        cnta++;
      }
      if (cntb > cnta) return false;
    }
    return true;
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