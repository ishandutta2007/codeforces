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
const int N = 500015, mod = 1e9 + 7;
int qpow(int a, int b) {
	int res = 1;

	while (b) {
		if (b & 1) res = (ll) res * a % mod;

		a = (ll) a * a % mod;
		b >>= 1;
	}

	return res;
}
int n, a[N], fac[N], ifac[N];
void init(int m) {
	fac[0] = ifac[0] = 1;

	rep(i, 1, m) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * qpow(i, mod - 2) % mod;
}

int C(int x, int y) {
	if (x < y || y < 0) return 0;

	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	init(410000);
	rep(i, 0, n) scanf("%d", &a[i]);
	int as = 0;

	rep(x, 0, n) {
		as += C(x + a[x], x + 1), as %= mod;
	}

	printf("%d\n", as);
	return 0;
}