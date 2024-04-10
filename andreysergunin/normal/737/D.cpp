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
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;    

const int INF = 1e9;

int n;
vector<int> a;
vector<int> pref;


const int MAXN = 4010;

// vector<vector<vector<int>>> dp[2];

int dp[2][MAXN][MAXN][2];


int main() {
	ios_base::sync_with_stdio(0);

	cin >> n;
    // n = 4000;
	a.resize(n);
    // for (int i = 0; i < n; ++i)
        // a[i] = rand() + 10;
	    
	for (int i = 0; i < n; ++i)
	 	cin >> a[i];

	// dp[0].resize(MAXN, vector<vector<int>>(MAXN, vector<int>(2)));
	// dp[1].resize(MAXN, vector<vector<int>>(MAXN, vector<int>(2)));

	pref.resize(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];

	int cur = 0;

	for (int k = (sqrt(2 * n) + 5); k > 0; --k) {
		for (int l = n; l >= (k / 2) * (k / 2); --l)
			for (int r = n - l - k; r >= ((k - 1) / 2) * ((k - 1) / 2 + 1) ; --r) {
				// cout << k << " " << l << " " << r << endl;
				
				int y = dp[cur ^ 1][l + k][r][1] + pref[l + k] - pref[l];
				if (l + k + r + 1 <= n) {
				    int x = dp[cur][l + k + 1][r][1] + pref[l + k + 1] - pref[l];
					dp[cur ^ 1][l][r][0] = (y > x ? y : x);
				} else 
				    dp[cur ^ 1][l][r][0] = y;

				y = dp[cur ^ 1][l][r + k][0] - pref[n - r] + pref[n - r - k];
				if (l + k + r + 1 <= n) {
				    int x = dp[cur][l][r + k + 1][0] - pref[n - r] + pref[n - r - k - 1];
					dp[cur ^ 1][l][r][1] = (y < x ? y : x);
				} else 
				    dp[cur ^ 1][l][r][1] = y;
			}
		cur ^= 1;
	}

	cout << dp[cur][0][0][0] << endl;


	return 0;
}