#include <bits/stdc++.h>

using namespace std;

const int MX = 100, MAGIC = 1000000;

int a[MX];
long long S;

long long calc(int n, long long d) {
	if (d > 1e9 + 42) return d * n - S;
	
	long long sum = 0;
	for (int j = 0, dd = d; j < n; j++) {
		int r = a[j] % dd;
		sum += r > 0 ? dd - r : 0;
	}
	
	return sum;
}

int main() {
	int n;
	long long k;
	ignore = scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	S = 0;
	for (int i = 0; i < n; i++) S += a[i];
	
	vector<long long> vec = {MAGIC, (long long)1e12};
	for (int i = 0; i < n; i++)
		for (int p = 1; a[i] / p > MAGIC; p++)
			vec.emplace_back(a[i] / p);
	
	sort(vec.begin(), vec.end());
	
	long long ans = -1;
	for (size_t i = vec.size(); i > 0 && ans == -1; i--) {
		long long L = vec[i - 1] + 1;
		long long R = vec[i];
		if (L > R || calc(n, L) > k) continue;
		
		while (L < R) {
			long long C = (L + R + 1) / 2;
			if (calc(n, C) > k) R = C - 1;
			else L = C;
		}
		
		ans = R;
	}
	
	if (ans == -1) ans = MAGIC;
	while (calc(n, ans) > k) ans--;
	
	for (int i = 0; i < n; i++)
		for (int j = 1; a[i] / j > max(ans, MAGIC * 1ll); j++)
			if (a[i] % j == 0 && calc(n, a[i] / j) <= k)
				ans = a[i] / j;
	
	printf("%lld\n", ans);
	
	return 0;
}