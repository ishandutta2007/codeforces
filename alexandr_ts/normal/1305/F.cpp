#include <memory>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <random>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
ll a[N];

vector<ll> GetPrimes(ll x) {
	vector<ll> primes;
	while (x > 1) {
		bool fnd = false;
		for (ll i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				primes.push_back(i);
				while (x % i == 0) {
					x /= i;
				}
				fnd = true;
			}
		}
		if (!fnd) {
			primes.push_back(x);
			x = 1;
		}
	}
	return primes;
}

ll solve(int n, ll p) {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < p) {
			ans += (p - a[i]);
		}
		else {
			ll r = a[i] % p;
			ans += min(r, p - r);
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	double start_time = clock();
	ll answer = n + 1;

	mt19937 gen(123);

	for (int it = 0; it < 30; ++it) {
		int j = gen() % n;
		for (int d = -1; d <= 1; ++d) {
			auto primes = GetPrimes(a[j] + d);
			for (auto p : primes) {
				answer = min(answer, solve(n, p));
			}
		}
	}

	cout << answer << endl;
}