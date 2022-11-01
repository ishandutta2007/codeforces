#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;

void solve() {
	ll p, f;
	cin >> p >> f;
	ll cs, cw, s, w;
	cin >> cs >> cw >> s >> w;
	if (s > w) {
		swap(s, w);
		swap(cs, cw);
	}

	ll best = 0;
	for (int i = 0; i <= cs; ++i) {
		ll cur = i;
		if (i * s > p) break;
		ll cs1 = cs;
		ll cw1 = cw;
		cs1 -= i;
		ll tmp = min(cw1, (p - i * s) / w);
		cur += tmp;
		cw1 -= tmp;
	
		ll tmp1 = min(f / s, cs1);
		cur += tmp1;

		ll tmp2 = min((f - tmp1 * s) / w, cw1);
		cur += tmp2;
		best = max(best, cur);
	}
	cout << best << "\n";
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