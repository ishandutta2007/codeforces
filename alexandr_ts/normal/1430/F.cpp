#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

struct W {
	ll l, r, a;
	ll minb;
} a[N];

void solve() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].l >> a[i].r >> a[i].a;
	}

	for (int i = n - 1; i >= 0; --i) {
		ll nxt = 0;
		if (i < n - 1 && a[i + 1].l == a[i].r) {
			nxt = a[i + 1].minb;
		}

		ll cnt_ms = nxt + a[i].a;

		ll t = a[i].r - a[i].l;	
		if (t * k >= cnt_ms) {
			a[i].minb = 0;
		} else if ((t + 1) * k < cnt_ms) {
			a[i].minb = INF;
			cout << "-1\n";
			return;
		} else {
			a[i].minb = cnt_ms - t * k;
		}
		//cout << a[i].minb << endl;
	}

	ll cur = k;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].minb > cur) {
			ans += cur;
			cur = k;
		}
		ll x = 0;
		if (a[i].a >= cur) {
			x = (a[i].a - cur + k - 1) / k;
		} else {
			x = 0;
		}
		cur = cur + x * k - a[i].a;
		ans += a[i].a;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}