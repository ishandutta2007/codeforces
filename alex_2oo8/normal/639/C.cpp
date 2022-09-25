#include<bits/stdc++.h>

using namespace std;

const int MX = 300000;

long long a[MX], b[MX];

int main() {
	int n, k, l = MX, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		scanf("%lld", a + i);
		
		b[i] += a[i];
		
		if (b[i] > 1) {
			b[i + 1] += b[i] / 2;
			b[i] %= 2;
		}
		else if (b[i] < 0) {
			b[i + 1] -= -b[i] / 2;
			b[i] %= 2;
		}
		
		if (l == MX && b[i] != 0) l = i;
	}
	
	long long x = b[n + 1];
	for (int i = n; i >= 0; i--) {
		x = 2 * x + b[i];
		if (abs(x) > 2 * k) break;
		
		if (i <= l && abs(a[i] - x) <= k && (i != n || a[i] != x)) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}