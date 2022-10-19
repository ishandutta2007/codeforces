/*input
4
2
1 2
3
2 0 1
4
2 0 5 1
5
0 1 1 0 1

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

int64_t calc(vector<int64_t> a) {
	int n = (int) a.size() - 1;

	vector<int64_t> dp(n + 1, -1e18);
	dp[0] = 0;
	vector<set<int>> vec(n + 1);
	for (int i = 0; i <= n; ++i) for (int j = 0; j < (n + 7); ++j) vec[i].insert(j);

	FOR(i, 1, n) {
		FOR(j, 1, i) {
			if (vec[j].find(a[i]) != vec[j].end()) vec[j].erase(a[i]);
			dp[i] = max(dp[i], dp[j - 1] + 1 + *vec[j].begin());
		}
	}
	return accumulate(dp.begin(), dp.end(), (int64_t) 0);
}

void solve() {
	int n; cin >> n;
	vector<int64_t> a(n + 1);
	FOR(i, 1, n) cin >> a[i];
	int64_t ans = 0;
	do {
		ans += calc(a);
		a.erase(a.begin() + 1);
	} while ((int) a.size() > 1);
	cout << ans << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) solve();

	return 0;
}