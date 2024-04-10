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

const int mod = 1e9 + 7;

long long modPow(long long n, long long k) {
	long long res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = (res * n) % mod;
		n = (n * n) % mod;
	}
	return res;
}

long long inv(long long x) {
	return modPow(x, mod - 2);
}

int n, m;
int a[(int)1e5];
int b[(int)1e5];
long long dp[(int)1e5];

long long f(int i) {
	if (i == n)
		return 0;
	if (dp[i] != -1)
		return dp[i];
	if (a[i] && b[i]) {
		if (a[i] == b[i])
			return dp[i] = f(i + 1);
		return dp[i] = a[i] > b[i];
	}
	long long probEq = inv(m);
	long long probGr;
	if (!a[i] && !b[i]) {
		probGr = (1 - probEq + mod) * inv(2) % mod;
	}
	else if(a[i]) {
		probGr = (a[i] - 1) * inv(m);
	}
	else {
		probGr = (m - b[i]) * inv(m);
	}
	return dp[i] = (probEq * f(i + 1) % mod + probGr) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, -1, sizeof dp);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	cout << (m == 1 ? 0 : f(0));
	return 0;
}