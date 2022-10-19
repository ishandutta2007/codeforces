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
const int mod = 998244353;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
const int g = 3, ig = qpow(g, mod - 2);
using poly = vector<int>;
int lim, rev[555555];
void init(int n, int m) {
	lim = 1;
	int w = 0;
	while(lim <= n + m - 2) lim <<= 1, w++;
	rev[0] = 0;
	rep(i, 1, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (w - 1));
}
void NTT(poly &a, int flag) {
	rep(i, 0, lim - 1) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 1; i < lim; i <<= 1) {
		int wn = qpow(flag == 1 ? g : ig, (mod - 1) / (i << 1));
		for(int j = 0; j < lim; j += (i << 1)) {
			for(int k = 0, w = 1; k < i; ++k, w = (ll) w * wn % mod) {
				int x = a[j + k], y = (ll) a[j + k + i] * w % mod;
				a[j + k] = x + y;
				a[j + k + i] = x - y;
				if(a[j + k] >= mod) a[j + k] -= mod;
				if(a[j + k + i] < 0) a[j + k + i] += mod;
			}
		}
	}
	if(flag == -1) {
		int div = qpow(lim, mod - 2);
		rep(i, 0, lim - 1) a[i] = (ll) a[i] * div % mod;
	}
}
poly operator * (poly a, poly b) {
	init(SZ(a), SZ(b));
	a.resize(lim);
	b.resize(lim);
	NTT(a, 1);
	NTT(b, 1);
	rep(i, 0, lim - 1) a[i] = (ll) a[i] * b[i] % mod;
	NTT(a, -1);
	return a;
}
const int N = 250015;
int n, son[N], fac[N];
VI e[N];
void dfs(int u, int pa) {
	for(auto v : e[u]) if(v != pa) {
		dfs(v, u);
		son[u]++;
	}
}
poly calc(int l, int r) {
	if(l == r) return (poly) {1, son[l]};
	int mid = (l + r) >> 1;
	poly L = calc(l, mid), R = calc(mid + 1, r);
	return L * R;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	poly F = calc(1, n);
	int ans = 0;
	rep(k, 0, n - 1) {
		int coef = (k & 1) ? mod - 1 : 1;
		(ans += (ll) coef * fac[n - k] % mod * F[k] % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}