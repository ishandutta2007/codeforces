#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int mod = (int)1e9 + 7;

int modPow(long long n, int p) {
	if (p == 0)
		return 1;
	n %= mod;
	if (p & 1)
		return (n * modPow(n, p - 1)) % mod;
	return modPow(n * n, p >> 1);
}

long long pr_a, pr_b;

int dp[1001][1001];

int f(int n, int k) { // numb. of a's, numb. of 'ab' subsequences left
	if (k <= 0)
		return 0;
	if (n >= k)
		return (n + dp[1][1] - 1) % mod;
	if (dp[n][k] != -1)
		return dp[n][k];
	return dp[n][k] = (pr_a * f(n + 1, k) + pr_b * (n + f(n, k-n))) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);

	int k;
	long long pa, pb;
	cin >> k >> pa >> pb;
	pr_a = (pa * modPow(pa + pb, mod - 2)) % mod;
	pr_b = (pb * modPow(pa + pb, mod - 2)) % mod;
	dp[1][1] = (1 + pr_a * modPow(pr_b, mod - 2)) % mod;

	cout << f(1, k);
	return 0;
}