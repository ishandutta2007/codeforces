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
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      ll x;
      cin >> x;
      sum += x;
      cnt.insert(x);
    }

    if (dfs(vector<ll>{sum})) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }

  }

private:
  multiset<ll> cnt;

  bool dfs(vector<ll> sum) {
    if (sum.empty()) {
      return true;
    }
    if (sum.size() > cnt.size()) {
      return false;
    }
    if (*prev(cnt.end()) > sum.back()) {
      return false;
    }
    vector<ll> new_vec;
    for (auto e : sum) {
      auto it = cnt.find(e);
      if (it != cnt.end()) {
        cnt.erase(it);
      } else {
        new_vec.push_back(e / 2);
        new_vec.push_back((e + 1) / 2);
      }
    }
    sort(new_vec.begin(), new_vec.end());
    return dfs(new_vec);
  }

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