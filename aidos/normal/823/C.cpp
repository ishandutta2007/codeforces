#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define forit(it, s)for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FNAME "a"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll k, a[111];
vector<ll> d;
ll D = 1;
ll S = 0;
ll LVL = 300300;

void check(ll d) {
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cur += (d - (a[i] % d)) % d;
	}
	if (cur <= k) D = max(D, d);
}

ll f(ll d) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll cur = a[i] / d + 1;
		res += cur;
		if (cur == 1) {
			res += n - i - 1;
			break;
		}
	}
	return res;
}

int get_next(ll X, ll L) {
	int l = L, r = (int)1e9 + 1123;
	int ans = L;
	while (l <= r) {
		int mid = (l + r) >> 1;
		ll val = f(mid);
		if (val < X) {
			r = mid - 1;
		} else {
			l = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

void add(set<pll> &s, ll L, ll R) {
	__typeof(s.begin()) it1 = s.lower_bound(mp(L, (ll)1e18));
	it1--;
	__typeof(s.begin()) it2 = s.lower_bound(mp(R, (ll)(1e18)));
	it2--;
	if (*it1 == *it2) {
		ll l = (*it1).f;
		ll r = (*it2).s;
		s.erase(it1);
		if (L > l) s.insert(mp(l, L - 1));
		s.insert(mp(L, R));
		if (r > R) s.insert(mp(R + 1, r));
	} else {
		ll l1 = (*it1).f;
		ll r1 = (*it1).s;
		s.erase(it1);
		if (L > l1) s.insert(mp(l1, L - 1));
		s.insert(mp(L, r1));
		ll l2 = (*it2).f;
		ll r2 = (*it2).s;
		s.erase(it2);
		s.insert(mp(l2, R));
		if (r2 > R) s.insert(mp(R + 1, r2));
	}
}

int main () {

	#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif


	cin >> n >> k;
	//n = 100;
	//k = (ll)1e11;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = (ll)1e9 - i;
		for (int j = 1; j * 1ll * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				d.pb(j);
				d.pb(a[i] / j);
			}
		}
		S += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 0; i < d.size(); i++) {
		check(d[i]);
	}

	for (ll d = 1; d <= LVL; d++) {
		check(d);
	}

	set<pll> s;
	s.insert(mp(LVL + 1, (ll)1e12));
	for (int i = 0; i < n; i++) {
		ll L = LVL + 1;
		ll X = (a[i] / L);
		while (X > 0) {
			ll RR = a[i] / X;
			ll RL = a[i] / (X + 1) + 1;
			ll R = RR;
			add(s, L, R);
			L = R + 1;
			X = (a[i] / L);
		}
		add(s, L, (ll)1e12);
	}

	forit (it, s) {
		ll L = (*it).f;
		ll R = (*it).s;
		ll X = f(L);
		// d <= (S + k) / X
		ll curd = min(R, (S + k) / X);
		if (curd >= L) D = max(D, curd);
	}

	printf("%lld\n", D);

	return 0;
}