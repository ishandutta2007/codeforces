#include <bits/stdc++.h>

using namespace std;

const int MX = 500001;

int d[MX];
long long s[MX + 1];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", d + i);
	
	sort(d, d + n);
	
	auto getMn = [](int n) {
		s[0] = 0;
		for (int i = 0; i < n; i++) s[i + 1] = s[i] + d[i];
		
		long long mn = 0;
		for (int k = 1, f = 0; k <= n; k++) {
			while (f < n && d[f] <= k) f++;
			
			long long LHS = s[n] - s[n - k];
			long long RHS = k * (k - 1ll) + s[min(n - k, f)] + max(n - k - f, 0) * 1ll * k;
			mn = max(mn, LHS - RHS);
		}
		
		return mn;
	};
	
	auto check = [&](int x) {
		int i = n;
		while (i > 0 && d[i - 1] > x) {
			d[i] = d[i - 1];
			i--;
		}
		d[i] = x;
		
		bool res = getMn(n + 1) == 0;
		
		while (i < n) {
			d[i] = d[i + 1];
			i++;
		}
		
		return res;
	};
	
	long long mn = getMn(n);
	
	if ((s[n] + mn) % 2 == 1) mn++;
	
	if (mn > n || check(mn) == false) {
		printf("%d\n", -1);
		return 0;
	}
	
	int mx = mn;
	for (int p = (1 << 20); p > 1; p /= 2)
		if (mx + p <= n && check(mx + p))
			mx += p;
	
	for (int ans = mn; ans <= mx; ans += 2) printf("%d ", ans);
	printf("\n");
	
	return 0;
}