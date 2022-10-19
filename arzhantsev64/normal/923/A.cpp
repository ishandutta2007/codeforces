#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<bool> prime(1e6 + 10, true);
	prime[0] = false;
	prime[1] = false;
	vector<int> primes;
	for (int i = 2; i < prime.size(); ++i) {
		if (prime[i]) {
			primes.push_back(i);
			for (int j = i * i; j < prime.size(); j += i)
				prime[j] = false;
		}
	}
	int x2;
	cin >> x2;
	int max_div = 0;
	for (auto i : primes)
		if (x2 % i == 0)
			max_div = i;
	int x1 = x2 - max_div + 1;
	int x0 = 2e6;
	for (auto i : primes)
		if (((x1 - 1) / i + 1) * i <= x2) {
			if (i <= (x1 - 1) - (x1 - 1) % i + 1)
				x0 = min(x0, (x1 - 1) - (x1 - 1) % i + 1);
		}
	cout << x0 << endl;
}