#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int mod = 998244353;
int dp[5001][5001];

long long modPow(long long n, long long p) {
	long long ans = 1;
	n %= mod;
	while (p) {
		if (p & 1)
			ans = (ans * n) % mod;
		n = (n * n) % mod;
		p >>= 1;
	}
	return ans;
}

const int &f(const int a, const int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (!a || !b)
		return dp[a][b] = 1;
	return dp[a][b] = (f(a - 1, b) + (long long)b * f(a - 1, b - 1)) % mod;
}

int main() {
	memset(dp, -1, sizeof dp);
	long long a, b, c;
	cin >> a >> b >> c;
	long long x = f(a, b);
	long long y = f(b, c);
	long long z = f(a, c);
	long long ans = (x*y) % mod;
	ans = (ans * z) % mod;
	cout << ans;
	return 0;
}