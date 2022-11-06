#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

const int maxn = 100000 + 5;

int N, K;
int a[maxn], Hash[maxn];
ll b[maxn];

int p[maxn], check[maxn];
void init() {
	rep(i, 2, 100000) {
		if (!check[i]) p[++p[0]] = i;
		for (register int j = 1; j <= p[0] && i * p[j] <= 100000; j++) {
			check[i*p[j]] = 1;
			if (!(i % p[j])) break;
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	init();
	rep(i, 1, N) scanf("%d", &a[i]), b[i] = 1;
	rep(i, 1, p[0]) {
		ll wty = 1;
		int ok = 1;
		rep(j, 1, K) {
			wty *= p[i];
			if (wty > 100000) { ok = 0; break; }
		}
		if (!ok) break;
		rep(j, 1, N)
			while (!(a[j] % wty)) a[j] /= wty;
	}
	rep(i, 1, N) {
		int x = a[i], pt = 1;
		if (x == 1) continue;
		while (check[x]) {
			if (!(x % p[pt])) {
				x /= p[pt];
				if (b[i] % p[pt]) b[i] *= p[pt];
			}
			else pt++;
		}
		if (b[i] % x) b[i] *= x;
	}
	rep(j, 1, N) Hash[a[j]]++;
	ll ans = 0;
	rep(j, 1, N) {
		ll wty = 1, ok = 1;
		rep(i, 1, K) {
			wty = wty * b[j];
			if (wty > 1e10) { ok = 0; break; }
		}
		if (!ok) continue;
		ll val = wty / a[j];
		if (val > 100000) continue;
		ans += Hash[val];
		if (val == a[j]) ans--;
	}
	printf("%lld", ans/2);
	return 0;
}