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

const int MAXN = 5100;
const int P = 1e9 + 7;

ll dp[MAXN][MAXN];

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> prev(256, -1);

	vector<int> sum(n);

	for (int i = 0; i < n; ++i) {
		if (prev[s[i]] != -1) {
			for (int j = 0; j < n; ++j) {
				sum[j] -= dp[prev[s[i]]][j];
				if (sum[j] < 0)
					sum[j] += P;
			}
		} 
		prev[s[i]] = i;
		
		for (int k = 'a'; k <= 'z'; ++k) {
			if (prev[k] != -1)
				++dp[i][0];
		}

		for (int j = 1; j < n; ++j) {
			dp[i][j] = sum[j - 1] + dp[i][j - 1];
			if (dp[i][j] >= P)
				dp[i][j] -= P;
 		}

 		for (int j = 0; j < n; ++j) {
			sum[j] += dp[prev[s[i]]][j];
			if (sum[j] >= P)
				sum[j] -= P;
		}
	}

	cout << dp[n - 1][n - 1] << endl;
	return 0;
}