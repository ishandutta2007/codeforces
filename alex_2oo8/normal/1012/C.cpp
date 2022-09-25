#include <bits/stdc++.h>

using namespace std;

const int MX = 5000, INF = 1e9;

int a[MX], dp[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	auto f = [&](int x) {
		int res = 0;
		if (x > 0 && a[x - 1] >= a[x]) res += a[x - 1] - a[x] + 1;
		if (x + 1 < n && a[x + 1] >= a[x]) res += a[x + 1] - a[x] + 1;
		return res;
	};
	
	for (int i = 0; i < n; i++) dp[i] = f(i);
	
	for (int it = 0; it < (n + 1) / 2; it++) {
		printf("%d\n", *min_element(dp, dp + n));
		
		int A = INF, B = INF, C = INF;
		for (int i = 0; i < n; i++) {
			int x = dp[i];
			dp[i] = A + f(i);
			if (i > 1) {
				int y = a[i - 1];
				a[i - 1] = min(a[i - 1], a[i - 2] - 1);
				dp[i] = min(dp[i], B + f(i));
				a[i - 1] = y;
			}
			
			A = min(A, B);
			B = C;
			C = x;
		}
	}
	
	return 0;
}