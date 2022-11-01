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
    map<int, int> cnt;
    for (auto& e : a) {
      cin >> e;
      cnt[e]++;
    }
    if (n % 2) {
      cout << "NO\n";
      return;
    }
    for (auto [k, v] : cnt) {
      if (v > n / 2) {
        cout << "NO\n";
        return;
      }
    }
    sort(a.begin(), a.end());

    vector<int> ans;

    for (int i = 0; i < n / 2; ++i) {
      ans.push_back(a[i]);
      ans.push_back(a[n / 2 + i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (ans[i] == ans[i + 1]) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";



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