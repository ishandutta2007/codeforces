#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MOD = 1000000007;

vector< vector<int> > lcp, dp;
vector<int> total;
string digits;
int n;

int cmnSz(int i1, int i2)
{
	for (int i = 0; i1 + i < digits.size() && i2 + i < digits.size(); ++i) {
		if (digits[i1 + i] != digits[i2 + i]) return i;
	}
	return digits.size() - max(i1, i2);
}

/*
bool sortCmp(int i1, int i2)
{
	for (int i = 0; i1 + i < digits.size() && i2 + i < digits.size(); ++i) {
		if (digits[i1 + i] < digits[i2 + i]) return 1;
		if (digits[i2 + i] < digits[i1 + i]) return 0;
	}
	return i1 > i2;
}
*/

bool myCmp(int i1, int i2, int sz)
{
    int cmn = lcp[i1][i2];
	if (sz <= cmn) return 0;

	// cmn < sz
	return digits[i1 + cmn] < digits[i2 + cmn];
}

void initLCP()
{
	// vector<int> sfxArr(n);
	lcp.assign(n, vector<int>(n));

	// for (int i = 0; i < n; ++i) sfxArr[i] = i;
	// sort(sfxArr.begin(), sfxArr.end(), sortCmp);

	/*
	for (int i = 0; i < sfxArr.size(); ++i) {
		cout << sfxArr[i] << endl;
	}
	*/

	/*
	for (int i1 = 0; i1 < n-1; ++i1) {
		int i2 = i1 + 1;
		int i = sfxArr[i1], j = sfxArr[i2];
		lcp[i][j] = lcp[j][i] = cmnSz(i, j);

		for (i2 = i1 + 2; i2 < n; ++i2) {
			j = sfxArr[i2];
			lcp[i][j] = lcp[j][i] = min(lcp[i][sfxArr[i2-1]], cmnSz(i, j));
		}
	}
	*/

	for (int i = 0; i < n-1; ++i) {
		lcp[i][n-1] = lcp[n-1][i] = (digits[i] == digits[n-1] ? 1 : 0);
	}

    for (int j = n-2; j >= 1; --j) {
		for (int i = j-1; i >= 0; --i) {
			lcp[i][j] = lcp[j][i] = (digits[i] == digits[j] ? 1 + lcp[i+1][j+1] : 0);
		}
    }
}

int main()
{
	cin >> n >> digits;
	initLCP();
	dp.assign(n, vector<int>(n+1, 0));
	// total.assign(n+1, 0);

	for (int j = 1; j <= n; ++j) {
		dp[0][j] = 1;
		// total[j] = 1;
	}

	// cout << myCmp(0, 1, 1) << endl;

	for (int i = 1; i < n; ++i) {
		int total = 0;
		for (int j = 1; i+j <= n; ++j) {
			if (digits[i] == '0') {
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = total;
			if (i >= j) total = (total + dp[i-j][j]) % MOD;
            if (i-j >= 0 && myCmp(i-j, i, j)) dp[i][j] = (dp[i][j] + dp[i-j][j]) % MOD;
            // cout << i << ' ' << j << ": " << dp[i][j] << endl;
		}

		// Re-calculate total
		/*
		for (int j = 1; i+j <= n; ++j) {
			if (i >= j) total[j] = (((total[j] - dp[i-j][j]) % MOD) + MOD) % MOD;
			total[j] = (total[j] + dp[i][j]) % MOD;
		}
		*/
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + dp[i][n-i]) % MOD;
	}
	cout << ans << endl;
}