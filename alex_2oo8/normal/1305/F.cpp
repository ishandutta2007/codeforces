#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, SQRT = 1100000;

vector<long long> getPrimes(long long L, long long R) {
	int n = R - L + 1;
	
	vector<long long> vec(n), primes;
	iota(vec.begin(), vec.end(), L);
	
	for (int p = 2; p < SQRT; p++) {
		int d = -L % p;
		if (d < 0) d += p;
		
		if (d >= n || vec[d] % p != 0) continue;
		
		for (int x = d; x < n; x += p) {
			while (vec[x] % p == 0) vec[x] /= p;
		}
		
		primes.push_back(p);
	}
	
	for (long long p : vec) {
		if (p > SQRT) primes.push_back(p);
	}
	
	return primes;
}

long long a[MX], s[MX + 1];

int main() {
	int n = MX;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%lld", a + i);
	/*
	for (int i = 0; i < n; i++) {
		a[i] = ((rand() * 1000000LL + rand()) % 1000000000000LL) | 1;
		assert(0 < a[i] && a[i] <= 1000000000000LL);
	}
	*/
	sort(a, a + n);
	
	auto primes = getPrimes(max(a[0] - n, 2LL), a[0] + n);
	
	reverse(a, a + n);
	
	s[n] = 0;
	for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + a[i];

	long long ans = n;
	for (auto p : primes) {
		long long cur = 0;
		int i;
		for (i = 0; i < n && a[i] >= p; i++) {
			long long rem = a[i] % p;
			rem = min(rem, p - rem);
			cur += rem;
			if (cur > ans) break;
		}
		
		if (cur > ans) continue;
		
		cur += p * (n - i) - s[i];
		
		ans = min(ans, cur);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}