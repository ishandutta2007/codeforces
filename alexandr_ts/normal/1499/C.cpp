#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  int n;
  cin >> n;
  vector<ll> c(n);
  for (auto& x: c) cin >> x;

  vector<ll> sum(n + 1), cnt(n + 1), mn(n + 1);
  sum[0] = c[0], sum[1] = c[1];
  cnt[0] = cnt[1] = 1;
  mn[0] = c[0], mn[1] = c[1];
  ll ans = c[0] * n + c[1] * n;

  auto calc = [&](int i) -> ll {
    return sum[i] + mn[i] * (n - cnt[i]);
  };
  for (int i = 2; i < n; ++i) {
    sum[i] = sum[i - 2] + c[i];
    cnt[i] = cnt[i - 2] + 1;
    mn[i] = min(mn[i - 2], c[i]); 
    //cout << calc(i) << " " << calc(i - 1) << endl;
    ans = min(ans, calc(i) + calc(i - 1));
  }

  cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}