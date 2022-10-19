#include<bits/stdc++.h>
#define int long long
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
using ll = long long;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int s2(int x) {
	return (ll) x * (x + 1) % mod * (2 * x + 1) % mod * qpow(6, mod - 2) % mod;
}
int n, q, a[N], pre[N], pre2[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld", &n, &q);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) pre[i] = (pre[i - 1] + a[i]) % mod;
	rep(i, 1, n) pre2[i] = (pre2[i - 1] + (ll) a[i] * a[i] % mod) % mod;
	while(q--) {
		int l, r, d;
		scanf("%lld%lld%lld", &l, &r, &d);
		int val = (ll) qpow(d, mod - 2) * ((ll) (r - l + 1) * a[l] % mod - pre[r] + pre[l - 1] + mod) % mod;
		int x = (ll) qpow(2 * (r - l + 1), mod - 2) * ((ll) 2 * val - (ll) (r - l) * (r - l + 1) % mod + mod) % mod;
		// printf("%lld %lld\n", val, x);
		int val2 = s2(x + (r - l)) - s2(x - 1) + mod;
		val2 %= mod;
		int cur2 = (ll) qpow(d, mod - 2) * qpow(d, mod - 2) % mod * ((ll) (r - l + 1) * a[l] % mod * a[l] % mod + mod - (ll) 2 * a[l] % mod * (pre[r] - pre[l - 1] + mod) % mod + (pre2[r] - pre2[l - 1] + mod)) % mod;
		// printf("2 %lld %lld\n", val2, cur2);
		if(val2 == cur2) puts("Yes");
		else puts("No");
	}
	return 0;
}