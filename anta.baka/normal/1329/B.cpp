#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iomanip>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int dp[31][30];

int sum(int a, int b, int m) {
	if ((a += b) >= m) {
		a -= m;
	}
	return a;
}

int dif(int a, int b, int m) {
	if ((a -= b) < 0) {
		a += m;
	}
	return a;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int d, m;
		cin >> d >> m;
		memset(dp, 0, sizeof(dp));
		for (int msb = 0; msb < 30; msb++) {
			dp[1][msb] = (1 << msb) % m;
		}
		for (int len = 2; len < 31; len++) {
			for (int msb = 0; msb < 30; msb++) {
				for (int p = 0; p < msb; p++) {
					dp[len][msb] = sum(dp[len][msb], 1LL * dp[len - 1][p] * (1 << msb) % m, m);
				}
			}
		}
		vi kek;
		{
			int tmp = d;
			while (tmp) {
				kek.pb(tmp & 1);
				tmp >>= 1;
			}
			reverse(all(kek));
		}
		int ans = 0;
		for (int len = 1; len < 31; len++) {
			for (int msb = 0; msb < sz(kek) - 1; msb++) {
				ans = sum(ans, dp[len][msb], m);
			}
		}
		int ways = (d - (1 << (sz(kek) - 1)) + 1) % m;
		ans = sum(ans, ways, m);
		for (int len = 2; len < 31; len++) {
			for (int msb = 0; msb < sz(kek) - 1; msb++) {
				ans = sum(ans, 1LL * ways * dp[len - 1][msb] % m, m);
			}
		}
		cout << ans << '\n';
	}
}