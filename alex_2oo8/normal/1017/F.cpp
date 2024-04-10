#include <bits/stdc++.h>

using namespace std;

const int MX = 300000000, MAGIC = MX / 100, PRIME_MX = MAGIC / 10;

bool isPrime[MAGIC];
unsigned primes[PRIME_MX];

int main() {
	unsigned n, a, b, c, d, ans = 0;
	ignore = scanf("%u %u %u %u %u", &n, &a, &b, &c, &d);
	
	auto f = [&](unsigned p) {
		return ((a * p + b) * p + c) * p + d;
	};
	
	int primeCnt = 0;
	for (unsigned i = 2; i < PRIME_MX; i++)
		if (primes[i] == 0) {
			primes[primeCnt++] = i;
			for (int j = 2 * i; j < PRIME_MX; j += i)
				primes[j] = 1;
			
			unsigned nn = n, sum = 0;
			while (nn >= i) {
				nn /= i;
				sum += nn;
			}
			
			ans += f(i) * sum;
		}
	
	for (int it = 0; it < 100; it++) {
		memset(isPrime, 255, sizeof isPrime);
		
		int L = it * MAGIC;
		for (int i : primes) {
			int x = i * i;
			if (x >= L + MAGIC) break;
			if (x < L) x += (L - x + i - 1) / i * i;
			x -= L;
			while (x < MAGIC) {
				isPrime[x] = false;
				x += i;
			}
		}
		
		for (int i = 0; i < MAGIC; i++)
			if (isPrime[i] && L + i > PRIME_MX) {
				ans += f(L + i) * (n / (L + i));
			}
	}
	
	printf("%u\n", ans);
	
	return 0;
}