#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXM 200002

ll n, m, a, d;
ll period;
ll t[MAXM];

inline ll closest(ll T) {
	ll l = -1, r = n + 1;
	while(l + 1 < r) {
		ll mid = (l + r) / 2;
		if (mid * a <= T)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf(I64 I64 I64 I64, &n, &m, &a, &d);
	{
		ll l = 0, r = n;
		while(l + 1 < r) {
			ll mid = (l + r) / 2;
			if (mid * a <= d)
				l = mid;
			else
				r = mid;
		}
		period = r;
	}
	ll rightest = -ll(1e18), ans = 0, cur = 1;
	for (int i = 0; i < m; ++i) {
		scanf(I64, &t[i]);
		if (rightest >= t[i]) continue;
		ll cl = closest(t[i]);
		if (cur <= cl && cur <= n && cur * a <= t[i]) {
			ll w = (cl - cur + 1 + period - 1) / period;
			ans += w;
			rightest = (cur + (w - 1) * period) * a + d;
			cur = min(n + 1, cur + w * period);
		}
		if (rightest >= t[i]) continue;
	   ++ans;
		rightest = t[i] + d;
		{
			ll l = -1, r = n + 1;
			while(l + 1 < r) {
				ll mid = (l + r) / 2;
				if (mid * a <= rightest)
					l = mid;
				else
					r = mid;
			}
			cur = r;
		}
	}
	if (cur <= n) {
		ll w = (n - cur + 1 + period - 1) / period;
		ans += w;
	}

	cout << ans << endl;
	                    
	return 0;
}