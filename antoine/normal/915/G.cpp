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

/*

dp[i] = i^n - dp[i/2] - dp[i/3] - dp[i/4] - ... - dp[i/i]


*/

long long modPow(long long n, int k) {
	long long res = 1;
	n %= mod;
	while (k) {
		if (k & 1)
			res = (res * n) % mod;
		k >>= 1;
		n = (n*n) % mod;
	}
	return res;
}

const int KLIMIT = (int)2e6 + 5;

int dp[KLIMIT]; // resize
int a[KLIMIT] = { 0 };

vector<int> events[KLIMIT];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= k; ++i)
		events[i].push_back(i);

	dp[0] = 0;
	dp[1] = 1;

	long long aSum = 0;
	long long ans = dp[1] ^ 1;

	for (int i = 2; i <= k; ++i) {
		for (auto &&d : events[i]) {
			if (i + d <= k)
				events[i + d].push_back(d);
			aSum -= a[d];
			a[d] = dp[i / d];
			aSum = (aSum + a[d]) % mod;
		}
		events[i].clear();

		dp[i] = (modPow(i, n) - aSum + mod) % mod;
		ans = (ans + (dp[i] ^ i)) % mod;
	}
	
	cout << ans;

	return 0;
}