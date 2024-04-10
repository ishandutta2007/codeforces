#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<int> primes;
void sieve_of_eratosthenes(int n) {
	primes.resize(n);
	for (int i = 2; i < n; ++i)
		primes[i] = i;
	for (int i = 2; i*i < n; ++i)
		if (primes[i])
			for (int j = i * i; j < n; j += i)
				primes[j] = 0;

	for (int i = 1; i < n; i++) {
		if (primes[i] == i) {
			primes[i] = primes[i - 1] + 1;
		}
		else {
			primes[i] = primes[i - 1];
		}
	}
}
vector<int> pa;
vector<int> t;
bool p(int a) {
	t.clear();
	while (a > 0) {
		t.push_back(a % 10);
		a /= 10;
	}
	for (int i = 0; i < t.size() / 2; i++) {
		if (t[i] != t[(int)t.size() - 1 - i])return false;
	}
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int P, Q;
	cin >> P >> Q;
	int MX = 1300000;
	sieve_of_eratosthenes(MX);
	pa.resize(MX, 0);
	for (int i = 1; i < pa.size(); i++) {
		if (p(i))pa[i] = pa[i - 1] + 1;
		else pa[i] = pa[i - 1];
	}

	for (int i = MX - 1; i > 0; i--) {
		if (Q * primes[i] <= P * pa[i]) {
			cout << i << endl;
			return 0;
		}
	}

	cout << "Palindromic tree is better than splay tree" << endl;
}