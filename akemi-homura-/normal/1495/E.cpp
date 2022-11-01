#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 5000005;
int n, t[N], a[N], b[N];
inline void Input() {
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 1, lp = 0; i <= m; i++) {
		int p, k, seed, base;
		scanf("%d%d%d%d", &p, &k, &seed, &base);
		auto rnd = [&]() {
			int ret = seed;
			seed = (1ll * seed * base + 233) % mod;
			return ret;
		};
		for (int j = lp + 1; j <= p; j++) {
			t[j] = rnd() % 2;
			a[j] = b[j] = rnd() % k + 1;
		}
		lp = p;
	}
}
int main() {
	Input();
	long long s[2] = {0, 0};
	for (int i = 1; i <= n; i++) s[t[i]] += a[i];
	if (s[0] > s[1]) {
		swap(s[0], s[1]);
		for (int i = 1; i <= n; i++) t[i] ^= 1;
	}
	long long cur = t[1];
	for (int i = 1; i <= n; i++) {
		if (t[i]) {
			int mn = min(1ll * a[i], cur);
			a[i] -= mn;
			cur -= mn;
		} else {
			cur += a[i];
			a[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (t[i]) {
			int mn = min(1ll * a[i], cur);
			a[i] -= mn;
			cur -= mn;
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = (((1ll * i * i) ^ (b[i] - a[i])) + 1) % mod * ans % mod;
	}
	printf("%d\n", ans);
	return 0;
}