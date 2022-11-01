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
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int iter = 0;

    while (a.size() > 1) {
      vector<int> b(a.size() - 1);
      for (int i = 0; i + 1 < (int)a.size(); ++i) {
        b[i] = a[i + 1] - a[i];
      }
      sort(b.begin(), b.end(), greater<int>());
      if (b.back() != 0 && (int)b.size() < n - (iter + 1)) {
        b.push_back(0);
      }
      while (b.size() >= 2 && b.back() == 0 && b[(int)b.size() - 2] == 0) {
        b.pop_back();
      }
      reverse(b.begin(), b.end());
      a = std::move(b);
      iter++;
    }
    cout << a[0] << endl;

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