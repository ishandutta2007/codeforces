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

using namespace std;

const int mod = 1e9 + 7;
string X;
int D;
int dp[701][701][2];

const int f(const int i, const int k, const bool e) {
	if (i == X.size()) return !k;
	if (k < 0) return 0;
	if (dp[i][k][e] != -1)
		return dp[i][k][e];
	long long res = 0;
	const int limit = e ? X[i] - '0' : 9;
	for (int d = 0; d <= limit; ++d)
		res += f(i + 1, k - (d >= D), e && d == limit);
	return dp[i][k][e] = res % mod;
}

void bottomUp() {
	for (int i = X.size() - 1; i >= 0; --i)
		for (int k = 0; k <= X.size(); ++k)
			for (bool e : {0, 1})
				f(i, k, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X;
	long long ans = 0;
	for (D = 1; D <= 9; ++D) {
		memset(dp, -1, sizeof dp);
		bottomUp();
		long long c = 1;
		for (int k = 1; k <= X.size(); ++k) {
			ans = (ans + f(0, k, 1) * c) % mod;
			c = (c * 10 + 1) % mod;
		}
	}
	cout << ans;
	return 0;
}