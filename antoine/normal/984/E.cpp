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
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n;
int dp[8][10][10][10][10][10] = { 0 };
int x[2000], y[2000];

int ee(int i, int f, int a, int b, int c, int d) {
	int res = 0;

	// exit
	if (a == f) a = 0, ++res;
	if (b == f) b = 0, ++res;
	if (c == f) c = 0, ++res;
	if (d == f) d = 0, ++res;

	// enter
	if (!a && i != n && x[i] == f)
		a = y[i++], ++res;
	if (!b && i != n && x[i] == f)
		b = y[i++], ++res;
	if (!c && i != n && x[i] == f)
		c = y[i++], ++res;
	if (!d && i != n && x[i] == f)
		d = y[i++], ++res;

	return res + dp[i & 7][f][a][b][c][d];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	for (int i = n; i >= 0; --i)
		for (int a = 0; a <= 9; ++a)
			for (int b = 0; b <= 9; ++b)
				for (int c = 0; c <= 9; ++c)
					for (int d = 0; d <= 9; ++d) {
						for (int f = 1; f <= 9; ++f) {
							int &res = dp[i & 7][f][a][b][c][d] = (int)1e9;

							if (!(a | b | c | d) && i == n) {
								res = 0;
								continue;
							}

							res = ee(i, f, a, b, c, d);
						}

						// down
						for (int f = 2; f <= 9; ++f) {
							int &res = dp[i & 7][f][a][b][c][d];
							res = min(res, 1 + dp[i & 7][f - 1][a][b][c][d]);
						}

						// up
						for (int f = 8; f >= 1; --f) {
							int &res = dp[i & 7][f][a][b][c][d];
							res = min(res, 1 + dp[i & 7][f + 1][a][b][c][d]);
						}
					}

	cout << dp[0][1][0][0][0][0];
	return 0;
}