#include <bits/stdc++.h>

using namespace std;

const int MX = 1000001;

int f[MX], cnt[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	int good = 0;
	for (int i = 0, l, x; i < n; i++) {
		ignore = scanf("%d %d", &l, &x);
		
		bool dec = true;
		f[i] = x;
		for (int j = 1, y; j < l; j++) {
			ignore = scanf("%d", &y);
			if (y > x) dec = false;
			x = y;
		}
		
		if (dec) cnt[x]++;
		else {
			good++;
			i--;
			n--;
		}
	}
	
	long long ans = good * (2LL * n + good);
	
	for (int i = 1; i < MX; i++) cnt[i] += cnt[i - 1];
	
	for (int i = 0; i < n; i++) if (f[i] > 0) ans += cnt[f[i] - 1];
	
	printf("%lld\n", ans);
	
	return 0;
}