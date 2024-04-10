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

using namespace std;

const long long mod = 1e9 + 7;

long long modPow(long long n, long long k) {
	n %= mod;
	long long res = 1;
	for (; k; k >>= 1) {
		if (k & 1) {
			res = res * n % mod;
		}
		n = n * n % mod;
	}
	return res;
}

auto in() {
	int n;
	cin >> n;
	map<long long, long long> occ;
	while (n-- > 0) {
		int a;
		cin >> a;
		++occ[a];
	}
	return vector<pair<long long, long long>>(occ.begin(), occ.end());
}

const int NMax = 1e6;
long long fact[NMax + 1];
long long factInv[NMax + 1];

long long choose(long long n, long long k) {
	return fact[n] * factInv[k] % mod * factInv[n - k] % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fact[0] = factInv[0] = 1;
	for (int i = 1; i <= NMax; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		factInv[i] = modPow(fact[i], mod - 2);
	}

	auto v = in();
	vector<long long> dp(v.size(), 0);
	
	int count = v.back().second;
	for (int i = v.size() - 2; i >= 0; --i) {
		count += v[i].second;
		dp[i] = (v[i].first * v[i].second % mod * fact[count - 1] % mod + dp[i + 1] * choose(count, v[i].second) % mod * fact[v[i].second] % mod) % mod;
	}
	cout << dp[0];
	
 	return 0;
}