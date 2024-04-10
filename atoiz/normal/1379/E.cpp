/*input
9 3
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int SMALL = 100;
vector<vector<int>> dp;

bool check(int n, int k)
{
	if (n % 2 == 0 || k < 0) return false;
	if (n < SMALL) {
		if (find(dp[n].begin(), dp[n].end(), k) == dp[n].end()) return false;
	} else if (n & (n + 1)) {
		if (k == 0 || k >= n / 2) return false;
	} else {
		if (k == 1 || k >= n / 2) return false;
	}
	return true;
}

void solve(vector<int> &vec, int n, int offset, int k)
{
	assert(check(n, k));
	if (n == 1) return;
	for (int i = n - 2; ; i -= 2) {
		assert(i > 0);
		for (int j = min(k, max(10, i / 2)); j >= 0; --j) {
			// if (n < 20) cout << n << ' ' << k << " - " << i << ' ' << j << " + " << n - i - 1 << ' ' << k - j - (n > (n - i - 1) * 3) << endl;;
			if ((k - j - (n > (n - i - 1) * 3)) * 2 > n - i - 1) break;
			if (check(i, j) && check(n - i - 1, k - j - (n > (n - i - 1) * 3))) {
				vec[offset + 1] = offset + 1;
				solve(vec, i, offset + 1, j);
				vec[offset + i + 1] = offset + 1;
				solve(vec, n - i - 1, offset + 1 + i, k - j - (n > (n - i - 1) * 3));
				return;
			}
		}
	}
	assert(false);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp.resize(SMALL);
	dp[1] = {0};
	for (int i = 3; i < SMALL; i += 2) {
		vector<int> &cur = dp[i];
		for (int j = 1; j * 2 < i; j += 2) {
			for (int x : dp[j]) for (int y : dp[i - j - 1]) cur.push_back(x + y + (j * 3 < i));
		}
		sort(cur.begin(), cur.end());
		cur.erase(unique(cur.begin(), cur.end()), cur.end());
	}

	int n, k;
	cin >> n >> k;
	if (not check(n, k)) return cout << "NO" << endl, 0;

	vector<int> par(n, 0);
	solve(par, n, 0, k);
	cout << "YES" << endl;
	for (int x : par) cout << x << ' '; cout << endl;

	return 0;
}