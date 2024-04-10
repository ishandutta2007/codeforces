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
const int N = 300015, mod = 998244353;
int fac[N], ifac[N], f1[N], f2[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}

void init(int n = 300000) {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n], mod - 2);
	per(i, 0, n - 1) ifac[i] = (ll) ifac[i + 1] * (i + 1) % mod;

	f1[0] = f1[1] = 1;
	f2[0] = 1;

	rep(i, 2, n) {
		f1[i] = (f1[i - 1] + (ll) (i - 1) * f1[i - 2]) % mod;
		f2[i] = (ll) 2 * (i - 1) * f2[i - 2] % mod;
	}
}

int Binom(int n, int m) {
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	init();
	int n, t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		int ans = 0;

		for (int x = 0; x + x <= n; x ++) {
			ans = (ans + (ll) Binom(n - x, x) * f1[n - x - x] % mod * f2[x]) % mod;
		}

		printf("%d\n", ans);
	}
	return 0;
}