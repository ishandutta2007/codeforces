#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

int a[12][2000];
int best[2000][1 << 12];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		for (int j = 0; j < m; j++) {
			memset(best[j], 0, sizeof(best[j]));
			for (int m = 0; m < (1 << n); m++) {
				int val = 0;
				for (int i = 0; i < n; i++) {
					if ((m >> i) & 1) {
						val += a[i][j];
					}
				}
				int mm = m;
				for (int shift = 0; shift < n; shift++) {
					best[j][mm] = max(best[j][mm], val);
					int lo_bit = (mm >> (n - 1));
					mm = (mm << 1);
					if (mm & (1 << n)) mm ^= (1 << n);
					if (mm & 1) mm ^= 1;
					if (lo_bit) mm ^= 1;
				}
			}
		}
		vi dp(1 << n, 0);
		for (int j = 0; j < m; j++) {
			vi DP = dp;
			for (int m1 = 0; m1 < (1 << n); m1++) {
				for (int m2 = m1; ; m2 = (m2 - 1) & m1) {
					DP[m1] = max(DP[m1], dp[m1 ^ m2] + best[j][m2]);
					if (!m2) break;
				}
			}
			dp = DP;
		}
		cout << dp[(1 << n) - 1] << '\n';
	}
}