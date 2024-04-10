/*input
3
1 1 2 3 4 5

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
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>

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

const int MAXN = 26, MAXV = 50007;
int N, B[MAXN << 1];
bool flag[MAXN << 1];
int dp[MAXN][MAXV * MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	FOR(i, 1, 2 * N) cin >> B[i];
	sort(B + 1, B + 2 * N + 1);
	reverse(B + 1, B + 2 * N + 1);

	dp[0][0] = -1;
	FOR(i, 1, 2 * N - 2) FORB(j, min(i, N - 1), 1) {
		int cur_sum = accumulate(B + 1, B + j + 1, 0ll);
		FOR(k, B[i], cur_sum) {
			if (!dp[j][k] && dp[j - 1][k - B[i]]) dp[j][k] = i;
		}
	}

	int total = accumulate(B + 1, B + 2 * N - 1, 1) / 2;
	while (!dp[N - 1][total]) ++total;

	FORB(i, N - 1, 1) {
		int idx = dp[i][total];
		flag[idx] = 1;
		total -= B[idx];
	}

	cout << B[2 * N - 1] << ' ';
	FORB(i, 2 * N - 2, 1) if (flag[i]) cout << B[i] << ' ';
	cout << '\n';
	FOR(i, 1, 2 * N - 2) if (!flag[i]) cout << B[i] << ' ';
	cout << B[2 * N];
	return 0;
}