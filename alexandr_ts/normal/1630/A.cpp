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
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    if (k < n - 1) {
      swap(a[k], a[0]);
      for (int i = 0; i < n / 2; ++i) {
        cout << a[i] << " " << a[n - 1 - i] << "\n";
      }
    } else {
      if (n == 4) {
        cout << "-1\n";
        return;
      }
      swap(a[0], a[n / 2 - 1]);
      swap(a[1], a[n / 2]);
      for (int i = 0; i < n / 2; ++i) {
        cout << a[i] << " " << a[n - 1 - i] << "\n";
      }
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