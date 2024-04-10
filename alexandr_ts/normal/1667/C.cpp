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
    if (n % 3 == 0) {
      solve0(n);
    } else if (n % 3 == 1) {
      solve1(n);
    } else {
      solve2(n);
    }
    cout << a.size() << "\n";
    for (auto e : a) {
      cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
  }

private:
  void solve0(int n) {
    int k = n / 3;
    for (int i = 0; i < k; ++i) {
      a.push_back({i, k - 1 - i});
    }
    for (int i = 0; i < k - 1; ++i) {
      a.push_back({k + i, k + (k - 2 - i)});
    }
    a.push_back({2 * k - 1, 2 * k - 1});
  }

  void solve1(int n) {
    int k = (n + 2) / 3;
    for (int i = 0; i < k; ++i) {
      a.push_back({i, k - 1 - i});
    }
    for (int i = 0; i < k - 1; ++i) {
      a.push_back({k + i - 1, k + (k - 2 - i) - 1});
    }
  }

  void solve2(int n) {
    int k = (n + 1) / 3;
    for (int i = 0; i < k; ++i) {
      a.push_back({i, k - 1 - i});
    }
    for (int i = 0; i < k - 1; ++i) {
      a.push_back({k + i, k + (k - 2 - i)});
    }
  }

  vector<pair<int, int>> a;

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}