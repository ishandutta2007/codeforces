#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>


using namespace std;
typedef long long ll;

int spf[(int)1e7] = { 0 };

set<int> getPrimes(int n) {
	set<int> res;
	while (n > 1) {
		res.insert(spf[n]);
		n /= spf[n];
	}
	return res;
}

bool intersect(set<int> &s, set<int> &t) {
	for (auto &&x : t)
		if (s.count(x))
			return true;
	return false;
}

bool select(int a) {
	static set<int> s;
	auto primes = getPrimes(a);
	if (intersect(s, primes))
		return false;
	cout << a << ' ';
	for (auto &&x : primes) {
		s.insert(x);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 2; i < 1e7; ++i) {
		if (!spf[i]) {
			spf[i] = i;
			for (int j = i << 1; j < 1e7; j += i)
				if (!spf[j])
					spf[j] = i;
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (!select(a)) {
			while (!select(++a));
			int k = 2;
			while (++i < n) {
				while (spf[k] != k || !select(k))
					k++;
			}
		}
	}
	return 0;
}