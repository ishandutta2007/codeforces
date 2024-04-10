#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

#define ll long long

const signed ll llf = (signed ll) (~0ull >> 2);

typedef class Data {
	public:
		int a, b, k;

		Data() {	}

		void read() {
			scanf("%d%d%d", &a, &b, &k);
		}

		boolean operator < (Data x) {
			return b > x.b;
		}
} Data;

const int N = 505;

int n;
ll *f;
Data *d;

inline void init() {
	scanf("%d", &n);
	f = new ll[(n + 2)];
	d = new Data[(n + 1)];
	f[0] = 0;
	pfill(f + 1, f + n + 2, -llf);
	for (int i = 1; i <= n; i++) {
		d[i].read();
	}
}

inline void solve() {
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = n; ~j; j--) {
			if (f[j] != -llf) {
				f[j + 1] = max(f[j + 1], f[j] + d[i].a - j * 1ll * d[i].b);
				f[j] = max(f[j], f[j] + d[i].a - d[i].k * 1ll * d[i].b);
			}
		}
	}
	ll ans = -llf;
	for (int j = 0; j <= n; j++)
		ans = max(ans, f[j]);
	printf("%I64d", ans);
}

int main() {
	init();
	solve();
	return 0;
}