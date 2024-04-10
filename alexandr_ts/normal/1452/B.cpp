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
  vector<ll> v(n);
  for (auto& x: v) cin >> x;
  ll s = accumulate(v.begin(), v.end(), 0ll);
  ll add = 0;
  while ((s + add) % (n - 1)) add++;

  ll mx = *max_element(v.begin(), v.end());
  ll tmp = (s + add) / (n - 1);
  if (tmp < mx) {
    add += (mx - tmp) * (n - 1);
  }

  cout << add << "\n";
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