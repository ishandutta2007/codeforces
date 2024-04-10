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
const int N = 100015;
int n, m, mod, w, a[N], b[N];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
VI fac;
void fact(int x) {
	for(int i = 2; i * i <= x; i ++) {
		if(x % i == 0) fac.pb(i);
		while(x % i == 0) x /= i;
	}
	if(x > 1) fac.pb(x);
}
int ord(int x) {
	int res = mod - 1;
	for(int o : fac) {
		while(res % o == 0 && qpow(x, res / o) == 1) res /= o;
	}
	return res;
}
int lcm(int x, int y) {return x / __gcd(x, y) * y;}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &mod);
	fact(mod - 1);
	rep(i, 1, n) scanf("%d", &a[i]), a[i] = (mod - 1) / ord(a[i]);
	int g = 0;
	rep(i, 1, m) scanf("%d", &b[i]), g = __gcd(g, b[i]);
	VI vec;
	rep(i, 1, n) {
		int o = (ll) a[i] * g % (mod - 1);
		vec.pb(__gcd(mod - 1, o));
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	map<int, ll> F, G;
	F[1] = -1;
	for(auto x : vec) {
		G.clear();
		for(auto [a, b] : F) {
			G[a] += b;
			G[lcm(a, x)] -= b;
		}
		swap(F, G);
 	}
 	ll ans = 0;
 	for(auto [a, b] : F) ans += (ll) (mod - 1) / a * b;
 	printf("%lld\n", ans + mod - 1);
	return 0;
}