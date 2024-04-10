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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015, mod = 998244353;

int qpow(int a, int b) {
	int res = 1;

	while (b) {
		if (b & 1) res = (ll) res * a % mod;

		a = (ll) a * a % mod;
		b >>= 1;
	}

	return res;
}

int n, m, s[N], t[N], buc[N], fac[N], ifac[N], ooo[N];

int D[N];

void upd(int p, int v) {
	for (; p <= 200000; p += lowbit(p))(D[p] += v) %= mod;
}

int query(int p) {
	int res = 0;

	for (; p; p -= lowbit(p)) {
		(res += D[p]) %= mod;
	}

	return res;
}

int query(int l, int r) {
	return (query(r) + mod - query(l - 1)) % mod;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	fac[0] = ifac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = qpow(fac[i], mod - 2);
	rep(i, 1, n) scanf("%d", s + i), buc[s[i]]++;
	rep(j, 1, m) scanf("%d", t + j), ooo[t[j]]++;
	int ans = 0, cur = 1;
	rep(i, 1, 200000) {
		if (!buc[i]) continue;

		cur = (ll) cur * ifac[buc[i]] % mod;
		upd(i, (ll) fac[buc[i]] * ifac[buc[i] - 1] % mod);
	}
	rep(i, 1, min(n, m)) { // first pos differ
		(ans += (ll) query(1, t[i] - 1) * fac[n - i] % mod * cur % mod) %= mod;

		if (!buc[t[i]]) {
			break;
		}

		if (i == n && n < m) ans = (ans + 1) % mod;

		upd(t[i], mod - (ll) fac[buc[t[i]]] * ifac[buc[t[i]] - 1] % mod);

		cur = (ll) cur * fac[buc[t[i]]] % mod;
		buc[t[i]]--;
		cur = (ll) cur * ifac[buc[t[i]]] % mod;

		if (buc[t[i]]) upd(t[i], (ll) fac[buc[t[i]]] * ifac[buc[t[i]] - 1] % mod);

	}
	printf("%d\n", ans);
	return 0;
}