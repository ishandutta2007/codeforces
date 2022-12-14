#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second

typedef long long ll;
typedef pair<ll, ll> pie;

const int maxn = 1e5 + 100;

ll dp[maxn];
ll a[maxn];
ll b[maxn];

deque<pie> dq;

bool mustremove(pie fi, pie se, pie th) {
	return 1. * (se.L - fi.L) / (fi.R - se.R) <= 1. * (th.L - se.L) / (se.R - th.R);
}

void add(ll b, ll m) {
	while (dq.size() > 1) {
		pie last = dq.back();
		dq.pop_back();
		if (!mustremove({b, m}, last, dq.back())) {
			dq.push_back(last);
			break;
		}
	}
	dq.push_back({b, m});
}

ll gety(ll x, pie ln) {
	return ln.L + ln.R * x;
}

ll get(ll x) {
	while (dq.size() > 1) {
		pie last = dq.front();
		dq.pop_front();
		if (gety(x, last) < gety(x, dq.front())) {
			dq.push_front(last);
			break;
		}
	}
	return gety(x, dq.front());
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];

	dp[0] = 0;
	add(dp[0], b[0]);
	for (ll i = 1; i < n; i++) {
		dp[i] = get(a[i]);
		add(dp[i], b[i]);
	}
	cout << dp[n - 1] << endl;
}