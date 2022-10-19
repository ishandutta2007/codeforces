#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int n, t, c[N], g[N];
set<array<ll, 3>> S;

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &t);
	rep(i, 1, n) scanf("%d%d", &g[i], &c[i]), c[i] = (t - c[i]) % t;
	ll sum = 0;

	rep(i, 2, n) {
		int d;
		scanf("%d", &d);
		sum += d;
		c[i] -= sum % t;
		c[i] > 0 && (c[i] -= t);
	}

	S.insert({0, t - 1, 0});

	auto upd = [&](ll l, ll r) {
		auto it = S.lower_bound({l, 0, 0});
		ll mn = infll;

		if (it != S.begin()) {
			auto o = *prev(it);

			if (o[1] >= r) {
				S.erase(prev(it));
				S.insert({o[0], l - 1, o[2]});
				S.insert({r, o[1], o[2]});
				return;
			} else if (o[1] >= l) {
				S.erase(prev(it));
				S.insert({o[0], l - 1, o[2]});
				mn = min(mn, o[2] + r - o[1]);
			}
		}

		while (it != S.end() && (*it)[0] <= r) {
			auto o = *it;

			if (o[1] <= r) {
				mn = min(mn, o[2] + r - o[1]);
				it = S.erase(it);
			} else {
				it = S.erase(it);
				mn = min(mn, o[2]);
				S.insert({r + 1, o[1], o[2]});
			}
		}
		
		if (mn < infll)
			S.insert({r, r, mn});
	};

	rep(i, 1, n) {
		auto L = (*S.begin())[0];
		ll l = c[i] + g[i], r = c[i] + t, o = (L - c[i] + t - 1) / t;
		l += o * t, r += o * t;
		rep(p, -1, 0) upd(l + p * t, r + p * t);
	}

	ll ans = infll;
	for (auto o : S) ans = min(ans, o[2]);
	printf("%lld\n", ans + sum);
	return 0;
}