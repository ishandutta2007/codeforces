#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e18;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  ll solve(vector<ll> a, vector<ll> b) {
    ll base = 0;
    int n = a.size();
    for (auto e : a) {
      base += e * e * (n - 2);
    }
    for (auto e : b) {
      base += e * e * (n - 2);
    }

    ll sum_a = accumulate(a.begin(), a.end(), 0ll);
    ll sum_b = accumulate(b.begin(), b.end(), 0ll);
    ll sum = sum_a + sum_b;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= sum; ++j) {
        if (!dp[i][j]) continue;
        dp[i + 1][j + a[i]] = 1;
        dp[i + 1][j + b[i]] = 1;
      }
    }

    ll min_ans = INF;
    for (int i = 0; i <= sum; ++i) {
      if (dp[n][i]) {
        min_ans = min(min_ans, i * i + (sum - i) * (sum - i));
      }
    }
    // cout << "ma: " << min_ans << endl;

    base += min_ans;
    return base;
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    cout << Solver{}.solve(a, b) << "\n";
  }
}