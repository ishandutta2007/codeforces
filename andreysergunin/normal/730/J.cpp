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

const int INF = 2e9;

const int MAXN = 11000;

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	int sum = 0;
	
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {		
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; ++i) 
		cin >> b[i];

	vector< vector<int> > dp(MAXN, vector<int>(n + 1, -1));
	dp[0][0] = 0;
	vector< vector<int> > nextDp(MAXN, vector<int>(n + 1, -1));

	for (int i = 0; i < n; ++i) {
		nextDp = dp;
		for (int j = 0; j < MAXN; ++j) {
			if (j + b[i] >= MAXN)
				continue;
			for (int k = 0; k < n; ++k) {
				if (dp[j][k] != -1)
					nextDp[j + b[i]][k + 1] = max(nextDp[j + b[i]][k + 1], dp[j][k] + a[i]);
			}
		}

		swap(dp, nextDp);
	}

	int k = n;
	for (int i = sum; i < MAXN; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] != -1)
				k = min(k, j);
		}
	}

	int t = INF;
	for (int i = sum; i < MAXN; ++i) {
		if (dp[i][k] != -1)
			t = min(t, sum - dp[i][k]);
	}

	cout << k << " " << t << endl;
}