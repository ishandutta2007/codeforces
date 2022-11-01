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

  int solve(int a, int b) {
    if (a >= b) {
      return a - b;
    }

    if ((a | b) == b) {
      return 1;
    }

    int ans = INF;
    for (int newb = b; newb <= 2 * b; ++newb) {
      int cnt = calc(a, newb);
      ans = min(ans, newb - b + cnt);
    }
    return ans;
  }

private:
  int calc(int a, int b) {
    if (a >= b) return a - b;
    // cout << a << " " << b << endl;
    if ((a | b) == b) {
      return 1;
    }
    int i = 30;
    for (; i >= 0; --i) {
      if ((a & (1 << i)) && !(b & (1 << i))) {
        break;
      }
    }
    // cout << i << endl;

    int add = ((1 << (i + 1)) - 1) ^ (a & ((1 << (i + 1)) - 1));
    if (add == 0) ++add;
    return add + calc(a + add, b);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << Solver{}.solve(a, b) << "\n";
  }
}