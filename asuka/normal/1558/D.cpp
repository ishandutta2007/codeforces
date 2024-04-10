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
int fac[N << 1], ifac[N << 1];
int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int t, n, m, x[N], y[N];
int sum[N];
void add(int p, int v) {
	for(; p <= n; p += lowbit(p)) sum[p] += v;
}
int query(int p) {
	int res = 0;
	for(; p; p -= lowbit(p)) res += sum[p];
	return res;
}
int getpos(int x) { // xth
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(mid - query(mid) == x) {
			ans = mid;
		}
		if(mid - query(mid) < x) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	fac[0] = 1;
	rep(i, 1, 400000) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 0, 400000) ifac[i] = qpow(fac[i], mod - 2);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d", &x[i], &y[i]);
		int cnt = n - 1;
		VI vec;
		per(i, 1, m) {
			if(y[i] < n) {
				int p1 = getpos(y[i]);
				int p2 = getpos(y[i] + 1);
				// printf("%d %d\n", p1, p2);
				if(p1 + 1 == p2) cnt--;//, printf("%d\n", y[i]);
			} 
			int p = getpos(y[i]);
			add(p, 1);
			vec.pb(p);
		}
		printf("%d\n", C(n + cnt, n));
		for(auto x : vec) add(x, -1);
	}
	return 0;
}
// C(n + x, n);