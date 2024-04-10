#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
const int mod = 1e9 + 7;
int t, n, L, R, fac[N], ifac[N];
vector<pii> vec;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int fuck(pii u) {
	return min(abs(u.fi), abs(u.se));
}
int C(int n, int m) {
	if(n < m) return 0;
	if(m < 0) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &L, &R);
		fac[0] = ifac[0] = 1;
		rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
		rep(i, 1, n) ifac[i] = qpow(fac[i], mod - 2);
		vec.clear();
		vec.pb(mp(0, 0));
		rep(i, 1, n) vec.pb(mp(L - i, R - i));
		int up = inf;
		rep(i, 1, n) up = min(up, max(abs(vec[i].fi), abs(vec[i].se)));
		vec.pb(mp(up, up));
		// rep(i, 1, n) printf("%d %d\n", vec[i].fi, vec[i].se);
		sort(all(vec), [](pii u, pii v){return fuck(u) < fuck(v);});
		int pos, neg, ans;
		pos = neg = ans = 0;
		for(int l = 1, r = 0; l <= n + 1; l = r + 1) {
			int res = 0;
			r = l;
			while(r + 1 <= n + 1 && fuck(vec[r + 1]) == fuck(vec[l])) r++;
			int coef = fuck(vec[l]) - fuck(vec[l - 1]);
			if(n & 1) {
				// printf("C: %d %d\n", pos, neg);
				res += C(n - pos - neg, n / 2 - pos);
				res += C(n - pos - neg, n / 2 - neg);
			} else {
				res += C(n - pos - neg, n / 2 - pos);
			}
			rep(i, l, r) 
				if(vec[i].fi + vec[i].se > 0) pos++;
				else neg++;
			// printf("%d\n", res);
			res = (ll) res * coef % mod;
			ans = (ans + res) % mod;
		}	
		printf("%d\n", ans);
	}
	return 0;
}