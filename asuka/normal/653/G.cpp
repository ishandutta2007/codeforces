#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
const int mod = 1e9 + 7, i2 = mod + 1 / 2;
int n, a[N], pri[N], notp[N], low[N], tot;
int fac[N], ifac[N], coef[N];
VI vec[N], num;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
void init() {
	const int M = 300000;
	rep(i, 2, M) {
		if(!notp[i]) pri[++tot] = i, low[i] = i;
		for(int j = 1; j <= tot && i * pri[j] <= M; ++j) {
			notp[i * pri[j]] = 1;
			low[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}
int C(int a, int b) {
	return (ll) fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
int solve(VI u) {
	int m = SZ(u), res = 0;
	sort(all(u));
	// rep(i, 1, n - m) printf("0 ");
	// rep(i, n - m + 1, n) printf("%d ", u[i - (n - m) - 1]);
	// printf("\n");
	rep(i, n - m + 1, n) (res += (ll) u[i - (n - m) - 1] * coef[i] % mod) %= mod;
	rep(i, n - m + 1, n) (res += mod - ((ll) u[i - (n - m) - 1] * coef[n - i + 1] % mod)) %= mod;
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	scanf("%d", &n);
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 0, n) ifac[i] = qpow(fac[i], mod - 2);
	rep(i, 2, n) coef[i] = (coef[i - 1] + C(n - 1, i - 2)) % mod;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) {
		int x = a[i];
		// printf("I: %d\n", i);
		while(x > 1) {
			int u = low[x];
			num.pb(u);
			int cnt = 0;
			while(x % u == 0) x /= u, cnt++;
			vec[u].pb(cnt);
			// printf("(%d ^ %d)\n", u, cnt);
		}
	}
	sort(all(num));
	num.erase(unique(all(num)), num.end());
	int ans = 0;
	for(auto x : num) (ans += solve(vec[x])) %= mod;
	printf("%d\n", ans);
	return 0;
}