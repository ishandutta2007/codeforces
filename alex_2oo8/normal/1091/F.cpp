#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

long long l[MX], a[MX + 1], mn[MX + 1];
char s[MX + 1];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%lld", l + i);
	ignore = scanf("%s", s);
	
	long long e = 0, ans = 0;
	for (int i = 0, p = 5; i < n; i++) {
		a[i] = e;
		if (s[i] == 'G') {
			ans += 5 * l[i];
			e += l[i];
		}
		else if (s[i] == 'W') {
			ans += 3 * l[i];
			e += l[i];
			p = 3;
		}
		else {
			long long f = min(l[i], e);
			ans += l[i] + (l[i] - f) * p;
			e -= f;
		}
		a[i + 1] = e;
	}
	
	auto opt = [&](char c, int t) {
		mn[n] = a[n];
		for (int i = n - 1; i >= 0; i--) mn[i] = min(mn[i + 1], a[i]);
		
		long long delta = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				long long x = min(mn[i + 1] - delta, 2 * l[i]);
				ans -= x * (t - 1) / 2;
				delta += x;
			}
			a[i + 1] -= delta;
		}
	};
	
	opt('G', 5);
	opt('W', 3);
	
	printf("%lld\n", ans);
	
	return 0;
}