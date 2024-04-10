#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

bool prime(int x) {
	if (x == 1) return false;
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vi primes;
	for (int i = 1; i <= 70; i++) {
		if (prime(i)) {
			primes.pb(i);
		}
	}
	int n;
	cin >> n;
	vi basis(19, 0);
	int ans = 1;
	const int mod = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int msk = 0;
		for (int j = 0; j < 19; j++) {
			while (x % primes[j] == 0) {
				x /= primes[j];
				msk ^= (1 << j);
			}
		}
		x = msk;
		bool added = false;
		for (int b = 0; b < 19; b++) {
			if (!(x >> b & 1)) continue;
			if (!basis[b]) {
				basis[b] = x;
				added = true;
				break;
			}
			x ^= basis[b];
		}
		if (!added) {
			ans = 2 * ans % mod;
		}
	}
	cout << (ans - 1 + mod) % mod;
}