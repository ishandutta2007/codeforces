#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
mt19937_64 rnd(time(0));
vector<ll> fact;
namespace PR {
	ll mul(ll a, ll b, ll mod) {return (__int128) a * b % mod;}
	ll qpow(ll a, ll b, ll mod) {
		ll res = 1;
		while(b) {
			if(b & 1) res = mul(res, a, mod);
			a = mul(a, a, mod);
			b >>= 1;
		}
		return res;
	}
	bool MillerRabin(ll n) {
		if(n < 3 || n % 2 == 0) return n == 2;
		ll u = n - 1, t = 0;
		while(u % 2 == 0) u /= 2, t++;
		for(int a : {2, 3, 5, 7, 11, 13, 17, 19}) {
			if(n == a) return 1;
			ll x = qpow(a, u, n);
			for(int i = 1; i <= t; ++i) {
				ll nx = mul(x, x, n);
				if(x != 1 && x != n - 1 && nx == 1) return 0;
				x = nx;
			}
			if(x != 1) return 0;
		}
		return 1;
	}
	ll f(ll x, ll c, ll mod) {return (mul(x, x, mod) + c) % mod;}
	ll PollardRho(ll n) {
		ll s = 0, t = 0, c = rnd() % (n - 1) + 1;
		for(int _ = 1; ; _ <<= 1, s = t) {
			ll v = 1;
			rep(__, 1, _) {
				t = f(t, c, n);
				v = mul(v, abs(t - s), n);
				if(!(__ & 127) || __ == _) {
					ll g = __gcd(v, n);
					if(g > 1) return g;
				}
			}
		}
	}
	void solve(ll n) {
		if(MillerRabin(n)) {return fact.pb(n), void();}
		ll d = PollardRho(n);
		while(d == n) d = PollardRho(n);
		solve(d); solve(n / d);
	}
}
int n, f[1 << 15], g[1 << 15];
ll X, Y;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%lld%lld", &n, &X, &Y);
	if(Y % X) return puts("0"), 0;
	if(Y > X) PR::solve(Y / X);
	sort(all(fact));
	fact.erase(unique(all(fact)), fact.end());
	rep(_, 1, n) {
		ll o;
		scanf("%lld", &o);
		if(o % X == 0) {
			int mask = 0;
			rep(i, 0, SZ(fact) - 1) mask |= ((o / X) % fact[i] == 0) << i;
			f[mask]++;
		}
		if(Y % o == 0) {
			int mask = 0;
			rep(i, 0, SZ(fact) - 1) mask |= ((Y / o) % fact[i] == 0) << i;
			g[mask]++;
		}
	}
	ll ans = 0;
	int all = (1 << SZ(fact)) - 1;
	rep(S, 0, all) {
		int o = all ^ S;
		for(int SS = o; ; SS = (SS - 1) & o) {
			ans += (ll) f[S] * g[SS];
			if(!SS) break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}