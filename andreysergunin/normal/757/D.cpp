#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

const int MAXN = 20;
const int MAXM = 1 << MAXN;


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<int>> dp(n + 1, vector<int>(MAXM));

	for (int i = 0; i < n; ++i)
		dp[i][0] = 1;

	for (int i = 0; i < n; ++i) {
		int k = i;
		for (; k < n && s[k] == '0'; ++k);
		int cur = 0;
		for (int j = 0; j < 5 && k < n; ++j, ++k) {
			cur *= 2;
			cur += s[k] - '0';
			if (cur > MAXN)
				break;
			for (int mask = 0; mask < MAXM; ++mask) {
				int curMask = mask | (1 << (cur - 1)); 
				dp[k + 1][curMask] += dp[i][mask];
				if (dp[k + 1][curMask] >= P)
					dp[k + 1][curMask] -= P;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= MAXN; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans += dp[j][(1 << i) - 1];
			if (ans >= P)
				ans -= P;
		}
			
	}

	cout << ans << endl;

}