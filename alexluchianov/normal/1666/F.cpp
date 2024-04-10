#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int NMAX = 5005;

int dp[NMAX][NMAX], sp[NMAX][NMAX];

int lgput(int x, int p) {
	int ans = 1, aux = x;
	for (int i = 1; i <= p ; i = i << 1) {
		if (i & p)
			ans = 1LL * ans * aux % MOD;

		aux = 1LL * aux * aux % MOD;
	}

	return ans;
}

inline int invmod(int x) {
	return lgput(x, MOD - 2);
}

void solve() {
	int n;
	cin >> n;

	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n ; ++i) 
		cin >> a[i];

	int cnt = 0;
	int rev = 1;
	for (int i = 1; i <= n ; ++i) {
		if (i > 1 && a[i] == a[i - 1])
			++cnt;
		else if (i > 1 && cnt > 0) {
			++cnt;
			int fact = 1;
			for (int i = 2; i <= cnt ; ++i)
				fact = 1LL * fact * i % MOD;
			rev = 1LL * rev * fact % MOD;
			cnt = 0;
		}

		int pos = lower_bound(a.begin() + 1, a.end(), a[i]) - a.begin() - 1;
		if (pos == 0) continue;

		dp[i][1] = pos;
		sp[i][1] = (sp[i - 1][1] + 1LL * dp[i][1] * (pos - 1)) % MOD;

		for (int j = 2; j < i ; ++j) {
			//for (int k = 1; k < i ; ++k)
			//	dp[i][j] = dp[i][j] + dp[k][j - 1] * (k - 2 * j + 2);

			dp[i][j] = sp[pos][j - 1];
			sp[i][j] = (sp[i - 1][j] + 1LL * dp[i][j] * (pos - 2 * j + 1)) % MOD;
		}
	}

	if (cnt) {
		int fact = 1;
		for (int i = 2; i <= cnt ; ++i)
			fact = 1LL * fact * i % MOD;
		rev = 1LL * rev * fact % MOD;
		cnt = 0;
	}

	cout << 1LL * dp[n][n / 2] * invmod(rev) % MOD << endl;

	for (int i = 0; i <= n ; ++i)
		for (int j = 0; j <= n ; ++j)
			dp[i][j] = sp[i][j] = 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}