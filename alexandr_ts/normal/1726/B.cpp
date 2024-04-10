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
    int n, m;
    cin >> n >> m;
    if (m < n) {
      cout << "No\n";
      return;
    }

    if (n % 2) {
      cout << "Yes\n";
      for (int i = 0; i < n - 1; ++i) {
        cout << "1 ";
      }
      cout << (m - (n - 1)) << "\n";
      return;
    }

    if (m % 2 == 0) {
      cout << "Yes\n";
      for (int i = 0; i < n - 2; ++i) {
        cout << "1 ";
      }
      for (int i = 0; i < 2; ++i) {
        cout << (m - (n - 2)) / 2 << " ";
      }
      cout << "\n";
      return;
    }
    cout << "No\n";

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