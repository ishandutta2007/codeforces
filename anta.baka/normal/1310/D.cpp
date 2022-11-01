#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int n, k;
ll d[81][81];
ll dp[81][81];
ll ans = 1e18;
int arr[81];
mt19937 rng(228);

void relax() {
	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e18;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	while ((ld)clock() / CLOCKS_PER_SEC < 2.9) {
		for (int i = 0; i < n; i++) {
			arr[i] = rng() & 1;
		}
		relax();
		dp[0][0] = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				for (int kk = 0; kk < n; kk++) {
					if (arr[j] != arr[kk]) {
						dp[i + 1][kk] = min(dp[i + 1][kk], dp[i][j] + d[j][kk]);
					}
				}
			}
		}
		ans = min(ans, dp[k][0]);
	}
	cout << ans;
}