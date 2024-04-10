#include <bits/stdc++.h>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long

int n;
ll ans = 0;
char str[N];
ll len[N], energe[N], d[N];

inline void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf(Auto, len + i);
	scanf("%s", str + 1);
}

inline void solve() {
	boolean have_w = false;
	for (int i = 1; i <= n; i++) {
		ll &E = energe[i];
		E = energe[i - 1];
		if (str[i] == 'L') {
			ans += len[i];
			E -= len[i];
			if (E < 0) {
				if (have_w) {
					ans += -E * 3;
				} else {
					ans += -E * 5;
				}
				E = 0;
			}
		} else if (str[i] == 'W') {
			ans += len[i] * 3;
			E += len[i];
			have_w = true;
		} else if (str[i] == 'G') {
			ans += len[i] * 5;
			E += len[i];
		}
	}
	
	ll min_E = energe[n];	
	for (int i = n; i && min_E; i--) {
		min_E = min(min_E, energe[i]);
		if (str[i] == 'G') {
			ll take = min(min_E, len[i] << 1);
			min_E -= take;
			d[i] += take;
			ans -= take << 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		energe[i] -= (d[i] += d[i - 1]);
	}
	min_E = energe[n];
	for (int i = n; i && min_E; i--) {
		min_E = min(min_E, energe[i]);
		if (str[i] == 'W') {
			ll take = min(min_E, len[i] << 1);
			min_E -= take;
			ans -= take;
		}
	}
	printf(Auto"\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}