#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int mod = 1e9 + 7;
vector<int> primes;
int n;
int a[(int)1e5];
map<int, int> dp[(int)1e5];

bool isPrime(int i) {
	for (int j = 2; j < i; ++j)
		if (i % j == 0)
			return false;
	return true;
}

void getPrimes() {
	for (int i = 2; i < 70; ++i)
		if (isPrime(i))
			primes.push_back(i);
}

bool validMask(int m) {
	m &= ~15;
	m &= (m - 1);
	return !m;
}

int f(int i, int m) {
	if (i == n)
		return !m;
	if (dp[i].count(m))
		return dp[i][m];
	if (!validMask(m))
		return 0;
	return dp[i][m] = (f(i + 1, m) + f(i + 1, m ^ a[i])) % mod;
}

int main() {
	cin >> n;

	getPrimes();

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int mask = 0;
		for (int j = 0; j < primes.size(); ++j) {
			while (a[i] % primes[j] == 0) {
				a[i] /= primes[j];
				mask ^= 1 << j;
			}
		}
		a[i] = mask;
	}

	sort(a, a + n);

	cout << ((f(0, 0) + mod - 1) % mod);
	return 0;
}