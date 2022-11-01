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
    ll sum = n;
    int x;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      sum += x;
    }
    if (sum % 2) {
      cout << "errorgorn\n";
    } else {
      cout << "maomao90\n";
    }
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin>> t;
  while (t--) {
    Solver{}.solve();
  }
}