/*input
3
2 3
2 5 7
4 2 4
3 6
4 1 5 2 10 4
8 6 6 4 9 10
5 4 9 5 8 7
3 3
9 9 9
1 1 1
1 1 1

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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int INF = 1e7;
int N, M;

int solve()
{
	cin >> N >> M;
	vector<vector<int>> cols(M);
	FOR(i, 0, N - 1) FOR(j, 0, M - 1) {
		int x; cin >> x;
		cols[j].push_back(x);
	}
	while ((int) cols.size() < N) cols.emplace_back(N, 0);

	sort(ALL(cols), [&](vi v1, vi v2) { return *max_element(ALL(v1)) > *max_element(ALL(v2)); });
	cols.resize(N);

	vector<vector<int>> F(N, vector<int>(1 << N, 0));
	FOR(i, 0, N - 1) {
		FOR(mask, 0, (1 << N) - 1) {
			FOR(j, 0, N - 1) if ((mask >> j) & 1) {
				F[i][mask] += cols[i][j];
			}
		}

		FOR(j, 0, 3) {
			FOR(mask, 0, (1 << N) - 1) {
				int mask2 = (mask >> 1) ^ ((mask & 1) << (N - 1));
				F[i][mask] = max(F[i][mask], F[i][mask2]);
			}
		}

		// FOR(mask, 0, (1 << N) - 1) cout << i << ' ' << mask << ": " << F[i][mask] << endl;
	}

	vector<vector<int>> dp(N, vector<int>(1 << N, -INF));
	dp[0] = F[0];
	FOR(i, 1, N - 1) {
		FOR(mask, 0, (1 << N) - 1) {
			for (int mask2 = mask;; mask2 = mask & (mask2 - 1)) {
				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask2] + F[i][mask2 ^ mask]);
				if (mask2 == 0) break;
			}
		}
	}

	return dp[N - 1][(1 << N) - 1];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tests; cin >> tests;
	while (tests--) cout << solve() << '\n';

	return 0;
}