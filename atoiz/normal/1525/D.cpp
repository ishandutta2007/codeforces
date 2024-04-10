/*input
5
0 0 0 0 0

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

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	const int INF = 1e8;
	vector<int> dp(2 * n + 1, INF);
	dp[n] = 0;
	FOR(_, 1, n) {
		int x;
		cin >> x;
		FOR(i, 0, 2 * n) dp[i] += abs(n - i);
		if (x) {
			FOR(i, 0, 2 * n - 1) dp[i] = dp[i + 1];
			dp[2 * n] = INF;
		} else {
			FORB(i, 2 * n, 1) dp[i] = min(dp[i], dp[i - 1]);
		}
	}
	cout << dp[n] << endl;

	return 0;
}