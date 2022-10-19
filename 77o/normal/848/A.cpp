#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 30000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	if (k == 0) {
		cout << 'a' << endl;
		return 0;
	}
	vector<ll> dp(N);
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i < N; i++) {
		ll l = i / 2;
		ll r = i - l;
		dp[i] = l * r + dp[l] + dp[r];
	}
	// cout << dp[5] << endl;
	string s;
	for (char c = 'a'; c <= 'z' && k; c++) {
		for (int i = 2; i + 1 < N; i++) {
			if (dp[i] <= k && dp[i + 1] > k) {
				k -= dp[i];
				for (int j = 0; j < i; j++) s += c;
				break;
			}
		}
	}
	assert(k == 0);
	cout << s << endl;
	return 0;
}