#include <bits/stdc++.h>

using namespace std;

const int MX = 100000, MV = 10000001;

vector<int> prime;
vector<int> factor(int a) {
	vector<int> res;
	for (int p : prime) {
		if (a % p == 0) {
			res.push_back(p);
			a /= p;
			while (a % p == 0) a /= p;
		}
	}
	
	if (a > 1) res.push_back(a);
	return res;
}

vector<int> xs[MX];
int cnt[MV], cnt2[MV], a[MX];

int main() {
	for (int p = 2; p * p < MV; p++) {
		if (cnt[p] != 0) {
			cnt[p] = 0;
			continue;
		}
		prime.push_back(p);
		for (int q = 2 * p; q * q < MV; q += p) cnt[q] = 1;
	}
	
	int n, k;
	ignore = scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		ignore = scanf("%d", a + i);
		
		vector<int> primes = factor(a[i]);
		for (int p : primes) cnt2[p]++;
		int m = primes.size();
		for (int msk = 1; msk < (1 << m); msk++) {
			int v = 1, sgn = -1;
			for (int i = 0, mask = msk; i < m; i++) {
				if (mask & 1) v *= primes[i], sgn *= -1;
				mask /= 2;
			}
			
			xs[i].push_back(v);
			cnt[v] += sgn;
		}
	}
	
	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int x : xs[i]) {
			f += cnt[x];
		}
		
		if (n - f + 1 >= k) {
			printf("%d", i + 1);
			for (int j = 0; j < n; j++) {
				if (__gcd(a[i], a[j]) == 1 && k > 1) {
					printf(" %d", j + 1);
					k--;
				}
			}
			printf("\n");
			
			return 0;
		}
	}
	
	for (int p = 2; true; p++)
		if (cnt2[p] >= k) {
			for (int i = 0; i < n; i++)
				if (a[i] % p == 0 && k > 0) {
					printf("%d ", i + 1);
					k--;
				}
			break;
		}
	
	return 0;
}