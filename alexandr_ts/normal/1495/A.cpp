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
  vector<ll> xs, ys;
  int n;
  cin >> n;
  for(int i = 0; i < 2 * n; ++i) {
    ll x, y;
    cin >> x >> y;
    if (!x) {
      ys.push_back(y);
    } else {
      xs.push_back(x);
    }
  }
  sort(xs.begin(), xs.end(), [](int a, int b) {return abs(a) < abs(b);});
  sort(ys.begin(), ys.end(), [](int a, int b) {return abs(a) < abs(b);});
  ld ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += sqrt(xs[i] * xs[i] + ys[i] * ys[i]);
  }
  cout << fixed << setprecision(12) << ans << "\n";
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