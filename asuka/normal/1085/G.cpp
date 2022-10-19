#include<bits/stdc++.h>
#define ll long long
#define N 2005
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
int n, a[N][N], f[N][N], sum[N][N], fac[N], ifac[N], F[N], Co[N][N];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int inv(int x) {return qpow(x, mod - 2);}
void init() {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 0, n) ifac[i] = qpow(fac[i], mod - 2);
	F[2] = 1;
	rep(i, 3, n) F[i] = (ll) (i - 1) * (F[i - 1] + F[i - 2]) % mod;
	rep(i, 0, n) {
		Co[i][0] = 1;
		rep(j, 1, i) Co[i][j] = (Co[i - 1][j - 1] + Co[i - 1][j]) % mod;
	}
	f[0][0] = 1;
	rep(i, 1, n) {
		f[i][0] = fac[i];
		rep(j, 1, i) f[i][j] = (f[i][j - 1] + mod - f[i - 1][j - 1]) % mod;
	}
}
struct fenwick {
	int D[N];
	void clear() {memset(D, 0, sizeof D);}
	void add(int p, int v) {for(; p <= n; p += lowbit(p)) D[p] += v;}
	int query(int p) {int res = 0; for(; p; p -= lowbit(p)) res += D[p]; return res;}
} C[2];
int cnt[N], cnt2;
int solve(int p[], int q[]) {
	 // p   < q
	rep(i, 1, n) cnt[i] = 2;
	C[0].clear(); C[1].clear();
	rep(i, 1, n) C[1].add(i, 1);
	cnt2 = n;
	auto dec = [&](int x, bool flag) {
		if(x == 0) return;
		if(!flag) {
			if(cnt[x]-- == 2) C[1].add(x, -1), C[0].add(x, 1), cnt2--;
		} else {
			if(cnt[x]-- == 2) C[1].add(x, -1), cnt2--;
			else C[0].add(x, -1);
		}
	};
	int res = 0;
	rep(i, 1, n) {
		dec(p[i], 0);
		// printf("%d %d %d %d\n", C[1].query(q[i] - 1), f[n - i][cnt2 - 1], C[0].query(q[i] - 1), f[n - i][cnt2]);
		(res += (ll) C[1].query(q[i] - 1) * f[n - i][cnt2 - 1] % mod) %= mod;
		(res += (ll) C[0].query(q[i] - 1) * f[n - i][cnt2] % mod) %= mod;
		if(C[0].query(p[i]) - C[0].query(p[i] - 1) > 0 && p[i] < q[i]) (res += (mod - f[n - i][cnt2])) %= mod;//, puts("-----1");
		dec(q[i], 1);
	}
	return res;
}
int cantor(int p[]) {
	C[0].clear();
	int res = 0;
	rep(i, 1, n) {
		int cnt = (p[i] - 1) - C[0].query(p[i] - 1);
		(res += (ll) fac[n - i] * cnt % mod) %= mod;
		C[0].add(p[i], 1);
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	init();
	// rep(i, 1, 2) {
	// 	rep(j, 1, n) scanf("%d", &a[i][j]);
	// }
	// printf("%d\n", solve(a[1], a[2]));
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
	int ans = 0;
	rep(i, 1, n) {
		int coef = i == 1 ? cantor(a[i]) : solve(a[i - 1], a[i]);
		// printf("I %d %d\n", i, coef);
		(ans += (ll) coef * qpow(F[n], n - i) % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}